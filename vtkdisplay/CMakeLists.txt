cmake_minimum_required(VERSION 3.2)
project(vtkDisplay)

set(CMAKE_PREFIX_PATH "/home/liu/下载/opencv-4.8.0")
find_package(OpenCV 4 REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "   OpenCV Version: ${OpenCV_VERSION}")


set(CMAKE_CXX_STANDARD 14)

include_directories( "/usr/include/eigen3" )

add_executable(vtkDisplay vtkDisplay.cpp )
target_link_libraries(vtkDisplay ${OpenCV_LIBS} )

