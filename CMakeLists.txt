cmake_minimum_required(VERSION 3.8)
project(my_costmap_plugin)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(nav2_costmap_2d REQUIRED)
find_package(pluginlib REQUIRED)

# Include directories
include_directories(
  include
  ${nav2_costmap_2d_INCLUDE_DIRS}
)

# Add library
add_library(${PROJECT_NAME} SHARED
  src/my_costmap_plugin.cpp
)

# Declare dependencies
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  nav2_costmap_2d
  pluginlib
)

# Install the library
install(TARGETS ${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME}
)

# Install the headers
install(DIRECTORY include/
  DESTINATION include/${PROJECT_NAME}
)

# Install the plugin description XML
install(FILES plugin_description.xml
  DESTINATION share/${PROJECT_NAME}
)

# Export plugin
pluginlib_export_plugin_description_file(nav2_costmap_2d plugin_description.xml)

# Package setup
ament_package()

