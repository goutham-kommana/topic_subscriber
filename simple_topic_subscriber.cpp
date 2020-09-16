#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <std_msgs/Int32.h>

void counterCallback(const nav_msgs::Odometry::ConstPtr &odom_msg) {
  ROS_INFO("%s", odom_msg->header.frame_id.c_str());
  ROS_INFO("%f", odom_msg->twist.twist.linear.x);
  ROS_INFO("%f", odom_msg->twist.twist.angular.z);
}

int main(int argc, char **argv) {

  ros::init(argc, argv, "topic_subscriber");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("odom", 1000, counterCallback);

  ros::spin();

  return 0;
}