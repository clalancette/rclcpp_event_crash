#include <chrono>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

void create_pub(rclcpp::Node::SharedPtr node)
{
  for (int i = 0; i < 100; ++i) {
    //fprintf(stderr, "+++++++++++++++++++++ CREATING PUBLISHER ++++++++++++++++++\n");
    auto publisher = node->create_publisher<std_msgs::msg::String>("topic", 10);
  }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("minimal_publisher");
  std::thread thread{create_pub, node};
  rclcpp::spin(node);
  thread.join();
  rclcpp::shutdown();
  return 0;
}
