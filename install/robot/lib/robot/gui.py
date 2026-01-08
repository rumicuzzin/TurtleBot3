
#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String, Int32
import tkinter as tk
from tkinter import ttk

class RobotGUI(Node):
    def __init__(self):
        super().__init__('robot_gui')

        # ROS2: publisher & subscriber
        self.mode_pub = self.create_publisher(String, '/user_mode', 10)
        self.battery_sub = self.create_subscription(Int32, '/battery_level', self.battery_callback, 10)

        # GUI setup
        self.root = tk.Tk()
        self.root.title("🐢 TurtleBot Control Panel")
        self.root.geometry("600x400")
        self.root.configure(bg="#8cd48e")  # pastel green

        # Layout frames
        self.left_frame = tk.Frame(self.root, width=300, bg="#8cd48e")
        self.left_frame.pack(side="left", fill="both", expand=False)
        self.right_frame = tk.Frame(self.root, width=300, bg="#8cd48e")
        self.right_frame.pack(side="right", fill="both", expand=True, padx=10, pady=10)

        # Canvas for TurtleBot + explosion
        self.canvas = tk.Canvas(self.left_frame, width=300, height=400, bg="#8cd48e", highlightthickness=0)
        self.canvas.pack(fill="both", expand=True)

        # Explosion/starburst behind robot
        explosion_coords = [
            150, 50,
            160, 120,
            230, 130,
            170, 180,
            200, 250,
            150, 200,
            100, 250,
            130, 180,
            70, 130,
            140, 120
        ]
        self.canvas.create_polygon(explosion_coords, fill="white", outline="yellow", width=2)

        # TurtleBot image (make sure turtlebot.gif is in the same folder as this script)
        self.robot_image = tk.PhotoImage(file="src/turtlebot.gif").subsample(2,2)
        self.canvas.create_image(150, 200, image=self.robot_image)  # center

        # Right-hand controls
        ttk.Label(self.right_frame, text="Select Robot Mode:", font=("Arial", 12)).pack(pady=10)

        self.mode_var = tk.StringVar(value="docking_robot")
        self.mode_dropdown = ttk.Combobox(
            self.right_frame,
            textvariable=self.mode_var,
            values=["docking_robot", "delivery_robot", "inspection_robot"]
        )
        self.mode_dropdown.pack(pady=5)

        self.send_button = ttk.Button(self.right_frame, text="Send Mode", command=self.publish_mode)
        self.send_button.pack(pady=10)

        self.battery_label = ttk.Label(self.right_frame, text="Battery: Unknown", font=("Arial", 12))
        self.battery_label.pack(pady=15)

        self.status_label = ttk.Label(self.right_frame, text="Status: Ready", font=("Arial", 11))
        self.status_label.pack(pady=5)

        ttk.Button(self.right_frame, text="Exit", command=self.close_app).pack(pady=10)

        self.low_battery = False

        # ROS spin loop integrated with Tkinter
        self.root.after(100, self.ros_spin_once)

    def publish_mode(self):
        """Publish selected mode unless battery is too low"""
        if self.low_battery:
            self.get_logger().warn("Battery too low — cannot change mode!")
            self.status_label.config(text="⚠ Battery low — forced docking mode", foreground="red")
            return

        msg = String()
        msg.data = self.mode_var.get()
        self.mode_pub.publish(msg)
        self.status_label.config(text=f"Mode set to: {msg.data}", foreground="green")
        self.get_logger().info(f"Published user mode: {msg.data}")

    def battery_callback(self, msg):
        """Update battery label and enforce docking if low"""
        level = msg.data
        self.battery_label.config(text=f"Battery: {level}%")

        if level <= 20:
            if not self.low_battery:
                self.low_battery = True
                self.mode_var.set("docking_robot")
                self.mode_dropdown.config(state="disabled")
                self.send_button.config(state="disabled")
                self.status_label.config(text="Battery low — docking_robot enforced", foreground="red")

                # Publish docking mode
                dock_msg = String()
                dock_msg.data = "docking_robot"
                self.mode_pub.publish(dock_msg)
                self.get_logger().info("Battery low — published docking_robot mode.")
        else:
            if self.low_battery:
                self.low_battery = False
                self.mode_dropdown.config(state="normal")
                self.send_button.config(state="normal")
                self.status_label.config(text="Battery OK — user control restored", foreground="green")

    def ros_spin_once(self):
        rclpy.spin_once(self, timeout_sec=0.1)
        self.root.after(100, self.ros_spin_once)

    def close_app(self):
        self.get_logger().info("Closing GUI...")
        self.destroy_node()
        self.root.destroy()


def main(args=None):
    rclpy.init(args=args)
    gui = RobotGUI()
    gui.root.mainloop()
    rclpy.shutdown()


if __name__ == "__main__":
    main()