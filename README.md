# TurtleBot3
MTRX Project

The aim of this project is to use the TurtleBot3 burger as a common development platform, capable of emulating multiple robot types. 
The product capabilities include autonomously mapping the warehouse, moving along specific delivery routes and to user-selected damage sites. It also moves through the entire space to inspect for defects using the camera. Additionally, the robot docks when battery is low. Deliveries and defects are logged in human readable format and shown on the GUI, which additionally displays the user command buttons, battery level and warehouse map. 

## Installation Instructions

### Clone the repository
git clone https://github.com/rumicuzzin/TurtleBot3.git

This was a university team project - original repo cannot be publicly shared.

### Build the workspace
colcon build

source install/setup.bash

## Parameters

Each module has configurable parameters in YAML files located within its package when appropriate.
Edit these to tune system behavior (e.g., thresholds, rates, or exploration constants).


## Future Work

- Run executables on the turtlebot
- Dynamic UI updates via web interface
- Persistent map and data logging

