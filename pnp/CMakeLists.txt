cmake_minimum_required(VERSION 3.2)

project(pnp)

find_package(OpenCV 4 REQUIRED)
#find_package(Viz REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(pnp pnp.cpp)
target_link_libraries(pnp ${OpenCV_LIBS} )
