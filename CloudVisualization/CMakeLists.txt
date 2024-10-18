cmake_minimum_required(VERSION 3.23)
project(CloudVisualization)
find_package(PCL 1.3 REQUIRED)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
#add_executable(pcd_write_test pcd_write.cpp)


add_executable(CloudVisualization main.cpp)
target_link_libraries(CloudVisualization ${PCL_LIBRARIES})