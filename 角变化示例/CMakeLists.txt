cmake_minimum_required( VERSION 3.2)
project(jiao)

find_package(OpenCV 4 REQUIRED)
find_package(Eigen3 REQUIRED)

set(CMAKE_CXX_STANDARD 14)

#include_directories("/usr/include/eigen3")

add_executable(jiao jiao.cpp)
target_link_libraries(jiao ${OpenCV_LIBS} ${Eigen3_LIBS})
