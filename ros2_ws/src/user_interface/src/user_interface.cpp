// MTRX3760 2025 Project 2: Warehouse Robot DevKit
// File: user_interface.cpp
// Author(s): Matylda Hayne
//
// This file implements the main Pascal user interface. It handles GUI rendering
// with ImGui, map visualization, YAML parsing for task logs, and ROS 2
// communication for controlling the robot. The interface provides a split-pane
// layout with Pascal’s system status, map view, and user task controls.

#include "user_interface/user_interface.hpp"

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/int32.hpp>
#include <std_msgs/msg/string.hpp>
#include <shared_interfaces/srv/robot_type.hpp>

#include <ament_index_cpp/get_package_share_directory.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"
#include <yaml-cpp/yaml.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <atomic>
#include <algorithm>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

// ============================================================================

// helper for GLFW error
static void glfw_error_callback(int error, const char *description)
{
    std::cerr << "GLFW Error " << error << ": " << description << std::endl;
}

// tiny helpers / types
struct BatteryColours 
{
    static ImVec4 Green() { return {0.2f, 0.8f, 0.2f, 1.0f}; }
    static ImVec4 Yellow() { return {0.9f, 0.9f, 0.2f, 1.0f}; }
    static ImVec4 Red() { return {0.9f, 0.2f, 0.2f, 1.0f}; }
    static ImVec4 Background() { return {0.1f, 0.1f, 0.1f, 1.0f}; }
};

static bool LoadTextureFromFile(const char *filename, GLuint *out_texture, int *out_width, int *out_height)
{
    int width, height, channels;
    unsigned char *data = stbi_load(filename, &width, &height, &channels, 4);
    if (!data)
    {   
        return false;
    }
    
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    stbi_image_free(data);

    *out_texture = texture;
    *out_width = width;
    *out_height = height;
    return true;
}

// convert map.pgm -> map.png if needed
static bool ConvertPGMToPNG(const std::string &pgm_path, const std::string &png_path)
{
    int w, h, c;
    unsigned char *data = stbi_load(pgm_path.c_str(), &w, &h, &c, 1);
    if (!data)
    {
        return false;
    }
        
    bool ok = stbi_write_png(png_path.c_str(), w, h, 1, data, w);
    stbi_image_free(data);
    return ok;
}

// load raw pgm (for click validity)
static std::vector<unsigned char> loadPGM(const std::string &filename, int &width, int &height)
{
    std::ifstream file(filename, std::ios::binary);
    if (!file){
        return {};
    }

    std::string line;
    std::getline(file, line); // P5
    do
    {
        std::getline(file, line);
    } while (line[0] == '#');

    std::istringstream iss(line);
    iss >> width >> height;

    int max_val;
    file >> max_val;
    file.get();

    std::vector<unsigned char> data(width * height);
    file.read(reinterpret_cast<char *>(data.data()), width * height);
    return data;
}

// read indices from yaml (same as your original)
static std::vector<const char *> getIndexesFromYaml(const std::string &filename, std::vector<std::string> &tempStorage)
{
    tempStorage.clear();
    std::vector<const char *> result;
    try
    {
        YAML::Node yamlFile = YAML::LoadFile(filename);
        if (yamlFile["delivery"])
        {
            for (const auto &item : yamlFile["delivery"])
            {
                if (item["delivery_id"])
                {
                    tempStorage.push_back(std::to_string(item["delivery_id"].as<int>()));
                }
            }
        }
        else if (yamlFile["defect"])
        {
            for (const auto &item : yamlFile["defect"])
            {
                if (item["task_id"])
                {
                    tempStorage.push_back(std::to_string(item["task_id"].as<int>()));
                }
            }
        }

        for (const auto &s : tempStorage)
        {
            result.push_back(s.c_str());
        }
            
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error reading YAML: " << e.what() << std::endl;
    }
    return result;
}

// ============================================================================
//  UserInterface implementation
// ============================================================================

UserInterface::UserInterface()
{
}

UserInterface::~UserInterface()
{
    // cleanup in reverse order
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    if (pascal_texture_ != 0)
    {
        glDeleteTextures(1, &pascal_texture_);
    }
    if (map_texture_ != 0)
    {
        glDeleteTextures(1, &map_texture_);
    }
    if (window_)
    {
        glfwDestroyWindow(window_);
        glfwTerminate();
    }

    if (rclcpp::ok())
    {
        rclcpp::shutdown();
    }
}

bool UserInterface::Initialize()
{
    // GLFW + window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
    {
        std::cerr << "GLFW init failed\n";
        return false;
    }

    window_ = glfwCreateWindow(1280, 720, "Pascal UI", nullptr, nullptr);
    if (!window_)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }
    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1);
    glfwMaximizeWindow(window_);

    // GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cerr << "Failed to init GLEW\n";
        return false;
    }

    // ROS
    if (!rclcpp::ok())
    {
        rclcpp::init(0, nullptr);
    }
    node_ = rclcpp::Node::make_shared("user_interface");
    client_ = node_->create_client<shared_interfaces::srv::RobotType>("/robot_type");

    // subscriptions
    battery_sub_ = node_->create_subscription<std_msgs::msg::Int32>(
        "/battery_level", 10,
        [this](const std_msgs::msg::Int32::SharedPtr msg)
        {
            int v = std::clamp(msg->data, 0, 100);
            battery_level_.store(v);
        });

    current_type_sub_ = node_->create_subscription<std_msgs::msg::String>(
        "/current_type", 10,
        [this](const std_msgs::msg::String::SharedPtr msg)
        {
            current_type_ = msg->data;
            RCLCPP_INFO(node_->get_logger(), "Robot type: %s", msg->data.c_str());
        });

    // resources
    package_share_dir_ = ament_index_cpp::get_package_share_directory("user_interface");
    image_path_ = package_share_dir_ + "/resources/pascal.png";

    // intro text
    {
        std::string intro_path = package_share_dir_ + "/resources/pascal_intro.txt";
        std::ifstream in(intro_path);
        if (in)
        {
            std::ostringstream ss;
            ss << in.rdbuf();
            pascal_intro_ = ss.str();
        }
        else
        {
            pascal_intro_ = "Welcome to Pascal, your warehouse assistant robot!";
        }
    }
    // serial text
    {
        std::string serial_path = package_share_dir_ + "/resources/pascal_serial.txt";
        std::ifstream in(serial_path);
        if (in)
        {
            std::ostringstream ss;
            ss << in.rdbuf();
            pascal_serial_ = ss.str();
        }
        else
        {
            pascal_serial_ = "Serial ID Unavailable";
        }
    }

    // load robot image
    {
        bool ok = LoadTextureFromFile(image_path_.c_str(), &pascal_texture_, &pascal_width_, &pascal_height_);
        if (!ok)
        {
            std::cerr << "Failed to load pascal image from: " << image_path_ << std::endl;
        }
    }

    // load map from YAML
    {
        std::string map_yaml = package_share_dir_ + "/resources/map.yaml";
        try
        {
            YAML::Node cfg = YAML::LoadFile(map_yaml);
            std::string image_fname = cfg["image"].as<std::string>();
            map_resolution_ = cfg["resolution"].as<double>();
            auto origin_node = cfg["origin"];
            map_origin_[0] = origin_node[0].as<double>();
            map_origin_[1] = origin_node[1].as<double>();
            map_origin_[2] = origin_node[2].as<double>();

            std::filesystem::path yaml_dir = std::filesystem::path(map_yaml).parent_path();
            std::filesystem::path pgm_path = yaml_dir / image_fname;
            std::filesystem::path png_path = pgm_path;
            png_path.replace_extension(".png");

            if (!std::filesystem::exists(png_path))
            {
                ConvertPGMToPNG(pgm_path.string(), png_path.string());
            }

            if (!LoadTextureFromFile(png_path.string().c_str(), &map_texture_, &map_w_, &map_h_))
            {
                std::cerr << "Failed to load map png " << png_path << std::endl;
            }

            // also load raw pgm for click validation
            map_data_ = loadPGM(pgm_path.string(), map_w_, map_h_);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Map YAML load error: " << e.what() << std::endl;
        }
    }

    // ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    // load fonts just like your original
    std::string font_path = package_share_dir_ + "/resources/Roboto-Regular.ttf";
    if (!std::filesystem::exists(font_path))
    {
        font_path = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf";
    }
    default_font_ = io.Fonts->AddFontFromFileTTF(font_path.c_str(), 60.0f);

    std::string bold_path = package_share_dir_ + "/resources/Roboto-Bold.ttf";
    if (!std::filesystem::exists(bold_path))
    {
        bold_path = "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf";
    }
    bold_font_ = io.Fonts->AddFontFromFileTTF(bold_path.c_str(), 60.0f);
    big_bold_font_ = io.Fonts->AddFontFromFileTTF(bold_path.c_str(), 100.0f);

    std::string it_path = package_share_dir_ + "/resources/Roboto-Italic.ttf";
    if (!std::filesystem::exists(it_path))
    {
        it_path = "/usr/share/fonts/truetype/dejavu/DejaVuSans-Oblique.ttf";
    }
    italic_font_ = io.Fonts->AddFontFromFileTTF(it_path.c_str(), 60.0f);

    big_font_ = io.Fonts->AddFontFromFileTTF(font_path.c_str(), 100.0f);
    medium_font_ = io.Fonts->AddFontFromFileTTF(font_path.c_str(), 80.0f);
    mini_font_ = io.Fonts->AddFontFromFileTTF(font_path.c_str(), 40.0f);
    mini_italic_font_ = io.Fonts->AddFontFromFileTTF(it_path.c_str(), 40.0f);

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window_, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    std::cout << "Pascal UI Initialized Successfully\n";
    return true;
}

void UserInterface::Run()
{
    using RobotTypeClient = rclcpp::Client<shared_interfaces::srv::RobotType>;
    ImGuiIO &io = ImGui::GetIO();

    while (!glfwWindowShouldClose(window_))
    {
        glfwPollEvents();
        rclcpp::spin_some(node_);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // full-screen window, no bg (we draw green ourselves)
        ImGuiWindowFlags flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
            ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBackground;
        ImGui::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ImGui::SetNextWindowSize(io.DisplaySize, ImGuiCond_Always);
        ImGui::Begin("Control Panel", nullptr, flags);

        // LEFT PANE ===========================================================
        float total_w = io.DisplaySize.x;
        float desired_w = pascal_width_ * 2.0f + 40.0f; // scale ~2
        float left_w = std::clamp(desired_w, 100.0f, total_w * 0.4f);

        ImGui::BeginChild("LeftPane", ImVec2(left_w, 0), true);
        {
            // "Pascal" centered
            if (medium_font_)
            {
                ImGui::PushFont(medium_font_);
            }
            ImVec2 tsize = ImGui::CalcTextSize("Pascal");
            float avail = ImGui::GetContentRegionAvail().x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (avail - tsize.x) * 0.5f);
            ImGui::Text("Pascal");
            if (medium_font_)
            {
                ImGui::PopFont();
            }

            ImGui::Separator();

            // image
            if (pascal_texture_)
            {
                float scale = 2.0f;
                float draw_w = pascal_width_ * scale;
                float draw_h = pascal_height_ * scale;
                float avail_w = ImGui::GetContentRegionAvail().x;
                if (draw_w > avail_w)
                {
                    float s = avail_w / draw_w;
                    draw_w *= s;
                    draw_h *= s;
                }
                float offset_x = (avail_w - draw_w) * 0.5f;
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + offset_x);
                ImGui::Image((ImTextureID)(intptr_t)pascal_texture_, ImVec2(draw_w, draw_h));
            }
            else
            {
                ImGui::Text("No texture loaded");
            }

            ImGui::TextWrapped("Serial ID: %s", pascal_serial_.c_str());
            ImGui::Separator();
            ImGui::Text("Battery Level:");
            {
                int level = battery_level_.load();
                ImVec4 color = (level > 60) ? BatteryColours::Green()
                    : (level > 30) ? BatteryColours::Yellow()
                    : BatteryColours::Red();
                ImGui::PushStyleColor(ImGuiCol_PlotHistogram, color);
                ImGui::PushStyleColor(ImGuiCol_FrameBg, BatteryColours::Background());
                char buf[32];
                snprintf(buf, sizeof(buf), "%d%%", level);
                ImGui::ProgressBar(level / 100.0f, ImVec2(-1.0f, 0.0f), buf);
                ImGui::PopStyleColor(2);
            }
        }
        ImGui::EndChild();

        ImGui::SameLine();

        // RIGHT PANE ==========================================================
        ImGui::BeginChild("RightPane", ImVec2(0, 0), false);
        {
            // Title
            if (big_bold_font_)
            {
                ImGui::PushFont(big_bold_font_);
            }
            ImVec2 tt = ImGui::CalcTextSize("Welcome to your TurtleBot!");
            float avail = ImGui::GetContentRegionAvail().x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (avail - tt.x) * 0.5f);
            ImGui::Text("Welcome to your TurtleBot!");
            if (big_bold_font_)
            {
                ImGui::PopFont();
            }
            ImGui::Separator();

            ImGui::TextWrapped("%s", pascal_intro_.c_str());
            ImGui::Separator();

            // Get Started
            if (medium_font_)
            {
                ImGui::PushFont(medium_font_);
            }
            ImVec2 gst = ImGui::CalcTextSize("Get Started");
            avail = ImGui::GetContentRegionAvail().x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (avail - gst.x) * 0.5f);
            ImGui::Text("Get Started");
            if (medium_font_)
            {
                ImGui::PopFont();
            }

            // Caption
            ImVec2 cap = ImGui::CalcTextSize("Press the button below to bootup Pascal:");
            avail = ImGui::GetContentRegionAvail().x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (avail - cap.x) * 0.5f);
            ImGui::Text("Press the button below to bootup Pascal:");

            const float btn_w = 500.0f;
            float region_boot_w = ImGui::GetContentRegionAvail().x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (region_boot_w - btn_w) * 0.5f);

            if (ImGui::Button("Bootup", ImVec2(btn_w, 0)))
            {
                auto req = std::make_shared<shared_interfaces::srv::RobotType::Request>();
                req->robot_type = "start";
                req->index = 0;
                req->pose.pose.position.x = 0.0;
                req->pose.pose.position.y = 0.0;
                req->pose.pose.position.z = 0.0;

                mode_locked_ = false;
                flagged_startup_ = true;

                if (!client_->wait_for_service(std::chrono::seconds(1)))
                {
                    RCLCPP_WARN(node_->get_logger(), "Service robot_type not available");
                }
                else
                {
                    client_->async_send_request(req, [this](RobotTypeClient::SharedFuture f)
                    {
                        auto res = f.get();
                        if (res && res->success)
                        {
                            RCLCPP_INFO(node_->get_logger(), "robot_type service succeeded");
                            mode_locked_ = false;
                            sequence_number_++;
                        }
                        else
                        {
                            RCLCPP_WARN(node_->get_logger(), "robot_type service failed");
                        } 
                    });
                }
            }

            ImGui::BeginDisabled(mode_locked_);
            // task selection
            static const char *items[] = {"Inspect", "Delivery"};
            static int current_item = 0;
            ImGui::Text("Select a task:");
            ImGui::SetNextItemWidth(650.0f);
            if (ImGui::BeginCombo("##user_mode", items[current_item]))
            {
                for (int n = 0; n < IM_ARRAYSIZE(items); ++n)
                {
                    bool selected = (current_item == n);
                    if (ImGui::Selectable(items[n], selected))
                    {
                        current_item = n;
                    }
                    if (selected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }
                ImGui::EndCombo();
            }

            ImGui::SameLine();

            // load indexes depending on mode
            std::string yaml_file;
            std::vector<const char *> indexes;
            if (current_item == 0)
            {
                yaml_file = package_share_dir_ + "/resources/defect_log.yaml";
                indexes = getIndexesFromYaml(yaml_file, temp_storage_);
                temp_storage_.insert(temp_storage_.begin(), "Explore");
                indexes.clear();
                for (auto &s : temp_storage_)
                {
                    indexes.push_back(s.c_str());
                }
            }
            else
            {
                yaml_file = package_share_dir_ + "/resources/delivery_log.yaml";
                indexes = getIndexesFromYaml(yaml_file, temp_storage_);
                temp_storage_.insert(temp_storage_.begin(), "Point on Map");
                indexes.clear();
                for (auto &s : temp_storage_)
                {
                    indexes.push_back(s.c_str());
                }
            }

            static int current_index = 0;
            if (current_index >= (int)indexes.size())
            {
                current_index = 0;
            }

            ImGui::SetNextItemWidth(650.0f);
            if (ImGui::BeginCombo("##user_index", indexes.empty() ? "None" : indexes[current_index]))
            {
                for (int n = 0; n < (int)indexes.size(); ++n)
                {
                    bool selected = (current_index == n);
                    if (ImGui::Selectable(indexes[n], selected))
                    {
                        current_index = n;
                    }
                    if (selected)
                    {
                        ImGui::SetItemDefaultFocus();
                    }
                }
                ImGui::EndCombo();
            }

            ImGui::SameLine();
            if (ImGui::Button("SEND", ImVec2(650, 0)))
            {
                std::string robot_mode = items[current_item];

                // Inspect + Explore
                if (robot_mode == "Inspect" && strcmp(indexes[current_index], "Explore") == 0)
                {
                    auto req = std::make_shared<shared_interfaces::srv::RobotType::Request>();
                    req->robot_type = "inspect";
                    req->index = 0;
                    req->pose.pose.position.x = 0.0;
                    req->pose.pose.position.y = 0.0;
                    req->pose.pose.position.z = 0.0;

                    if (client_->wait_for_service(std::chrono::seconds(1)))
                    {
                        client_->async_send_request(req, [this](RobotTypeClient::SharedFuture f)
                        {
                            auto res = f.get();
                            if (res && res->success)
                            {
                                RCLCPP_INFO(node_->get_logger(), "inspect+explore ok");
                                sequence_number_++;
                            }
                            else
                            {
                                RCLCPP_WARN(node_->get_logger(), "inspect+explore failed");
                            } 
                        });
                    }
                }
                // Delivery + Point on Map
                else if (robot_mode == "Delivery" && strcmp(indexes[current_index], "Point on Map") == 0 && has_click_)
                {
                    auto req = std::make_shared<shared_interfaces::srv::RobotType::Request>();
                    req->robot_type = "delivery";
                    req->index = 0;
                    req->pose.pose.position.x = last_world_x_;
                    req->pose.pose.position.y = last_world_y_;
                    req->pose.pose.position.z = 0.0;
                    if (client_->wait_for_service(std::chrono::seconds(1)))
                    {
                        client_->async_send_request(req, [this](RobotTypeClient::SharedFuture f)
                                                    {
                            auto res = f.get();
                            if (res && res->success)
                            {
                                RCLCPP_INFO(node_->get_logger(), "delivery+map ok");
                                sequence_number_++;
                            }
                            else
                            {
                                RCLCPP_WARN(node_->get_logger(), "delivery+map failed");
                            } 
                        });
                    }
                }
                else if (robot_mode == "Delivery" && strcmp(indexes[current_index], "Point on Map") == 0 && !has_click_)
                {
                    RCLCPP_INFO(node_->get_logger(), "Please click on the map first.");
                }
                else
                {
                    // YAML-based
                    try
                    {
                        YAML::Node yaml_data = YAML::LoadFile(yaml_file);
                        std::string key = (robot_mode == "Delivery") ? "delivery" : "defect";
                        if (!yaml_data[key] || !yaml_data[key].IsSequence())
                        {
                            throw std::runtime_error("Invalid YAML format");
                        }
                        int wanted_id = std::stoi(indexes[current_index]);
                        YAML::Node chosen;
                        for (const auto &entry : yaml_data[key])
                        {
                            if (robot_mode == "Delivery" && entry["delivery_id"] && entry["delivery_id"].as<int>() == wanted_id)
                            {
                                chosen = YAML::Node(entry);
                                break;
                            }
                            if (robot_mode == "Inspect" && entry["task_id"] && entry["task_id"].as<int>() == wanted_id)
                            {
                                chosen = YAML::Node(entry);
                                break;
                            }
                        }
                        if (!chosen)
                        {
                            throw std::runtime_error("Entry not found");
                        }

                        auto pose_vec = chosen["pose"].as<std::vector<double>>();
                        auto req = std::make_shared<shared_interfaces::srv::RobotType::Request>();
                        req->robot_type = robot_mode;
                        req->index = wanted_id;
                        req->pose.pose.position.x = pose_vec.size() > 0 ? pose_vec[0] : 0.0;
                        req->pose.pose.position.y = pose_vec.size() > 1 ? pose_vec[1] : 0.0;
                        req->pose.pose.position.z = pose_vec.size() > 2 ? pose_vec[2] : 0.0;

                        if (client_->wait_for_service(std::chrono::seconds(1)))
                        {
                            client_->async_send_request(req, [this](RobotTypeClient::SharedFuture f)
                            {
                                auto res = f.get();
                                if (res && res->success)
                                {
                                    RCLCPP_INFO(node_->get_logger(), "yaml-based request ok");
                                    sequence_number_++;
                                }
                                else
                                {
                                    RCLCPP_WARN(node_->get_logger(), "yaml-based request failed");
                                } 
                            });
                        }
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << "SEND failed: " << e.what() << std::endl;
                    }
                }
            }

            // current type line
            {
                if (mini_italic_font_)
                {
                    ImGui::PushFont(mini_italic_font_);
                }
                ImVec2 ts = ImGui::CalcTextSize("Current type: %s  ~  Your selection: %s", current_type_.c_str(), items[current_item]);
                float aa = ImGui::GetContentRegionAvail().x;
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (aa - ts.x) * 0.5f);
                ImGui::Text("Current type: %s  ~  Your selection: %s", current_type_.c_str(), items[current_item]);
                if (mini_italic_font_)
                {
                    ImGui::PopFont();
                }
            }

            ImGui::Separator();

            // NOW bottom split: map + tasks
            float region_w = ImGui::GetContentRegionAvail().x;
            float map_region_w = region_w * 0.66f;
            float log_region_w = region_w * 0.34f;
            float height_region = 950.0f;

            // MAP child --------------------------------------------------------
            ImGui::BeginChild("MapChild", ImVec2(map_region_w, height_region), true);
            {
                if (medium_font_)
                {
                    ImGui::PushFont(medium_font_);
                }
                ImVec2 mtx = ImGui::CalcTextSize("Inside your Warehouse");
                float va = ImGui::GetContentRegionAvail().x;
                ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (va - mtx.x) * 0.5f);
                ImGui::Text("Inside your Warehouse");
                if (medium_font_)
                {
                    ImGui::PopFont();
                }

                if (map_texture_ != 0)
                {
                    float max_w = map_region_w * 0.9f;
                    float draw_w = map_w_ * 5.0f;
                    float draw_h = map_h_ * 5.0f;
                    if (draw_w > max_w && draw_w > 0.0f)
                    {
                        float s = max_w / draw_w;
                        draw_w = max_w;
                        draw_h *= s;
                    }

                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + 8.0f);
                    ImGui::Image((ImTextureID)(intptr_t)map_texture_, ImVec2(draw_w, draw_h), ImVec2(0, 1), ImVec2(1, 0));

                    ImVec2 image_pos = ImGui::GetItemRectMin();
                    ImVec2 image_size(draw_w, draw_h);

                    ImDrawList *dl = ImGui::GetWindowDrawList();

                    // click -> marker
                    if (ImGui::IsItemHovered() && ImGui::IsMouseClicked(ImGuiMouseButton_Left))
                    {
                        ImVec2 mouse = ImGui::GetMousePos();
                        if (mouse.x >= image_pos.x && mouse.x <= image_pos.x + image_size.x &&
                            mouse.y >= image_pos.y && mouse.y <= image_pos.y + image_size.y)
                        {
                            float u = (mouse.x - image_pos.x) / image_size.x;
                            float v = 1.0f - ((mouse.y - image_pos.y) / image_size.y);

                            int px = std::clamp(int(u * map_w_), 0, map_w_ - 1);
                            int py = std::clamp(int(v * map_h_), 0, map_h_ - 1);

                            if (!map_data_.empty())
                            {
                                unsigned char pixel = map_data_[py * map_w_ + px];
                                if (pixel > 250)
                                {
                                    map_markers_.clear();
                                    map_markers_.push_back(ImVec2(mouse.x - image_pos.x, mouse.y - image_pos.y));

                                    last_world_x_ = map_origin_[0] + (px * map_resolution_);
                                    last_world_y_ = map_origin_[1] + ((map_h_ - py) * map_resolution_);
                                    has_click_ = true;
                                }
                                else
                                {
                                    std::cout << "Invalid click: not on free space\n";
                                }
                            }
                        }
                    }

                    for (auto &pt : map_markers_)
                    {
                        ImVec2 draw_pos(image_pos.x + pt.x, image_pos.y + pt.y);
                        dl->AddCircleFilled(draw_pos, 5.0f, IM_COL32(255, 0, 0, 255));
                    }

                    // clear map button
                    const float btn_clear_w = 500.0f;
                    float reg_clear = ImGui::GetContentRegionAvail().x;
                    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (reg_clear - btn_clear_w) * 0.5f);
                    if (ImGui::Button("Clear Map", ImVec2(btn_clear_w, 0)))
                    {
                        map_markers_.clear();
                        has_click_ = false;
                    }
                }
                else if (flagged_startup_)
                {
                    ImGui::Text("Currently mapping...");
                }
                else
                {
                    ImGui::Text("Awaiting Mapping...");
                }
            }
            ImGui::EndChild();

            ImGui::SameLine();

            // TASKS child ------------------------------------------------------
            ImGui::BeginChild("MapInfoPane", ImVec2(log_region_w, height_region), true);
            {
                ImGui::Text("Tasks");
                ImGui::Separator();
                ImGui::Spacing();

                std::string defect_yaml = package_share_dir_ + "/resources/defect_log.yaml";
                std::string delivery_yaml = package_share_dir_ + "/resources/delivery_log.yaml";

                // defects
                try
                {
                    YAML::Node yf = YAML::LoadFile(defect_yaml);
                    ImGui::PushFont(mini_font_);
                    if (yf["defect"])
                    {
                        for (size_t i = 0; i < yf["defect"].size(); ++i)
                        {
                            auto d = yf["defect"][i];
                            if (!d["pose"] || d["pose"].size() < 3)
                                continue;
                            auto pose = d["pose"];
                            bool complete = d["complete"] ? d["complete"].as<bool>() : false;
                            std::string status = complete ? "[resolved]" : "";
                            ImGui::Text("[%zu] defect at (%.1f, %.1f, %.1f) %s", i + 1,
                                pose[0].as<double>(), pose[1].as<double>(), pose[2].as<double>(),
                                status.c_str());
                        }
                    }
                    ImGui::PopFont();
                }
                catch (const std::exception &e)
                {
                    ImGui::Text("Failed to load defect yaml: %s", e.what());
                }

                // deliveries
                try
                {
                    YAML::Node yf = YAML::LoadFile(delivery_yaml);
                    ImGui::PushFont(mini_font_);
                    if (yf["delivery"])
                    {
                        for (size_t i = 0; i < yf["delivery"].size(); ++i)
                        {
                            auto d = yf["delivery"][i];
                            if (!d["pose"] || d["pose"].size() < 3)
                                continue;
                            auto pose = d["pose"];
                            bool complete = d["complete"] ? d["complete"].as<bool>() : false;
                            std::string status = complete ? "[completed]" : "";
                            ImGui::Text("[%zu] delivery to (%.1f, %.1f, %.1f) %s", i + 1,
                                pose[0].as<double>(), pose[1].as<double>(), pose[2].as<double>(),
                                status.c_str());
                        }
                    }
                    ImGui::PopFont();
                }
                catch (const std::exception &e)
                {
                    ImGui::Text("Failed to load delivery yaml: %s", e.what());
                }
            }
            ImGui::EndChild();
            ImGui::EndDisabled();
        }

        ImGui::EndChild();
        ImGui::End();

        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.5098f, 0.7294f, 0.5373f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window_);
    }
}