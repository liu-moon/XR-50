#include "xv_ros2_node.h"
using namespace xv;
using namespace std::chrono_literals;

void signalHandler(int signum) {}
int main(int argc, char **argv) 
{
    // 注册信号处理程序
    signal(SIGSEGV, signalHandler);

    // 初始化ROS2节点
    rclcpp::init(argc, argv);

    // 创建节点
    auto node = std::make_shared<xvision_ros2_node>();

    // 初始化节点
    node->init();

    // 运行节点
    rclcpp::spin(node);

    // 关闭节点
    rclcpp::shutdown();
    return 0;
}
