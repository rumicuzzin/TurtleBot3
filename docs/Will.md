# Pretty Little Lidars - Warehouse Robot DevKit Project

## Project Overview

### Approach:
- Explore Maze - first stage
- Use Map from exploration for navigation

### Required:
- Sensors; Lidar, Camera, Odom
- Battery Node - Constantly executing -> made up battery usage
- Setup NAV2
- Docking Location -> Can make this a global variable as it will not change

## Node Architecture - Questions and Decisions

### Perception Node:
Purpose - Centralises Lidar and Odometry sensor processing for both robot modes, providing clean, processed sensor data to other nodes.
Responsibilities:
- Subscribes to raw sensor topics
- Data processing, converts sensor data into appropriate reference frames
- Data Distribution, publishes processed data for other nodes to consume

ROS Interface:
Subcribes to:
- /scan
- /odom
- /tf
Publishes to:
- /perception/lidar_processed
- /perception/obstacles - maybe
- /perception/odom_processed - smoothed ODOM data
- /perception/robot_status - currnet pose

Lets make this node the source of truth for the turtlebot - we don't want other nodes to process the raw data differently.
Every time we want to know the turtlebots environment/position we should consult with this node. 

### Explore Node:
Purpose - Map out the environment.
Responsibilities:
- Wall following Algorithm
- Build Occupancy Grid as it goes
- Once Done, save map for future reference

ROS Interface:
Subscribes to:
- perception/lidar_processed
- /perception/obstacles - maybe
- /perception/odom_processed
- /perception/robot_status
- /defect_detector/camera
- /map | map/metadata - from slam
- /exploration/command - fromm logging - tell whether to start/stop exploration
  
Publishes to:
- /drive/cmd_vel

### Camera Node
Purpose - To see defects - can process camera data into readable format for defect detector to subscribe to
Responsibilities:
- As the Robot is exploring, this node will be running and publishing information about what the robot sees

Publishes to: 
- camera/processed_image - something like that

Subscribes to:
- camera/raw_image

This can be quite memory intensive - so maybe we can change the frame rate or something

### Defect Manager Node
Purpose - Construct defect Objects
Responsibilities: Detect defects as the robot is in exploration mode, instantiate defect objects with necessary data - some vision detection algorithm requiree to determine if defect exists. 

Publishes to: 
- defect/detected
- /defects/markers - For RVIZ if we want to tag it

Subscribes to:
- /map - when defect detected retreive current localation information using occupancy grid
- perception/odem_processed
- camera/processed - this reads in processed iamge data to feed into vision detection algorithm

From what I undertand, this node will only be necessary during exploration phase - navigation phase can use coordinated that are stored in every instance of a detect object


### Navigation Node - Path_Planner
Puprose - Given coordinate data, navigate the turtlebot to desired location

SOME NOTES 
{
- Can look into A* or Dijkstra's algorithms
- Essentially if we can successfully map defect/delivery/docking locations into the occupancy grid (Info on Occupancy grid [here](https://docs.ros.org/en/noetic/api/nav_msgs/html/msg/OccupancyGrid.html) -> consult chat for more info)
- A parameter can be passed into this navigation algorithm and this is all we will need for all cases
- Takes coordinates as input
- Outputs path plan
}

Responsiblities: For delivery, docking and defect location - this navigation algorithm can be used

Publishes to: 
- /drive/cmd_vel - this is what drive node will subscribe to -> what turns and velocities to execute etc
  
Subscribes to:
- /map - for path planning
- /perception.odom_processed - planning form specfic local
- /navigation/goal - this can be from logger or whatever - some coordinate point so the robot knows where to navigate to


### Drive Node
Purpose - Handles motor operations

Subscribes to:
- /drive/cmd_vel

Publishes to:
- /cmd_vel

Simple - lets keep movement operation completely separate from all other nodes to avoid confusion.

### Logging Node
Purpose - My understanding is this is some sort of user interface where it accepts commands via terminal, trigger high level actions across system. Accept user commands: "navigate to defect 3", "start delivery", "return to dock". Log all important events. 

Suscribes to:
- All node status topics - I havnt included these published topics in the nodes above (soz for confusion)

Publishes to:
- /navigation/goal - takes input for navigation 


## How It All Connects

We should have 2 different instances of a turtlebot. Lets say:

Instance 1: Dumb Turtlebot 
- This guy does not know its environment and thus must explore the map to become smart
- Requires camera node + perception

Instance 2: Smart Turtlebot
- This guy knows his surroundings
- Does not require camera node

Abstract turtle bot base class and then we derrive either a dumb or smart bot depending on the case. 

Our goal is to have a robot that will be able to explore the maze initially, whilst doing this, it will initialise all defect locations. And build a map. Using this map data structure ( NAV2 occupancy grid), lets try create a map with a resolution tailored to the size of our maze. 

From this, we can then pass in commands through the logging node. These commands will call upon the navigation node to navigate to the desired location, whether that is the defect/delivery/docking location.

There will be a function which is most likely going to be in the turtlebot/system node that has a battery consumption function - whenever that reaches a certain threshold it will override the rest of the program and navigate to the docking station using the navigation node and the global variable which is the docking stations position within the map.

The goal is to have the environment fully mapped, then all we need to do is pass through coordinates as parameters to the navigation node and it will be able to communicate with the drive node control the turtle bot to the desired location.

<img width="926" height="812" alt="image" src="https://github.com/user-attachments/assets/3bf89faa-6131-4719-92b7-3b2a4eb55288" />

Shitty node diagram - but it might help 

## Next Steps
1. Get basic movement working
2. Setup NAV2
3. Implement exploration and mapping
4. Add perception and defect detection
5. Create navigation with path planning
6. Implement battery management
7. Build UI/logging interface
8. Test and integrate all components
