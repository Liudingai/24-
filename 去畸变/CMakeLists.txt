cmake_minimum_required(VERSION 3.2)
project(example)

find_package(OpenCV 4 REQUIRED)
find_package(Eigen3 REQUIRED)

set(CMAKE_CXX_STANDARD 14)

#include_directories("")

add_executable(example example.cpp)
target_link_libraries(example ${OpenCV_LIBS} ${Eigen3_LIBS})
