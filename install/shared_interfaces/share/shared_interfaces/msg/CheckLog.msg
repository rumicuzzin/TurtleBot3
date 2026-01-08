# Custom Message for logger to publish
# From logger node

string task_type    # defect or delivery
int8 index          # logger to index based on when they receive them
geometry_msgs/PoseStamped pose
bool complete       # visited/delivered