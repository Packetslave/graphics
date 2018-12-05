cmake_minimum_required(VERSION 3.12)
project(graphics)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_PREFIX_PATH /Users/blanders/src/external/opencv-4.0.0/build)
find_package(OpenCV REQUIRED)

# -------- viewer

add_executable(viewer viewer.cpp)
target_link_libraries(viewer ${OpenCV_LIBS})
