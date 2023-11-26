cmake_minimum_required(VERSION 3.2)
project(viz)

#set(CMAKE_PREFIX_PATH "/home/zzl/opencv420/build/install/")
find_package(OpenCV 4 REQUIRED)
message(STATUS "OpenCV library status:")
message(STATUS "   OpenCV Version: ${OpenCV_VERSION}")


set(CMAKE_CXX_STANDARD 14)

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(viz viz.cpp )
target_link_libraries(viz ${OpenCV_LIBS} )


