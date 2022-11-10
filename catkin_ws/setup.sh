#!/bin/sh
source devel/setup.bash
export ROS_ROOT=/opt/ros/noetic/ros
export PATH=$ROS_ROOT/bin:$PATH
export PYTHONPATH=$ROS_ROOT/core/roslib/src:$PYTHONPATH
export ROS_PACKAGE_PATH=~/catkin_ws/opt/ros/noetic/share:$ROS_PACKAGE_PATH