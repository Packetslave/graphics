cmake_minimum_required(VERSION 3.12)
project(graphics)

set(CMAKE_CXX_STANDARD 14)

# -------- OpenCV

set(CMAKE_PREFIX_PATH /Users/blanders/src/external/opencv-4.0.0/build)
find_package(OpenCV REQUIRED)

# -------- Google ABSL

add_subdirectory(abseil-cpp)

# -------- viewer

add_executable(viewer viewer.cpp PPM.cpp PPM.h)
target_link_libraries(viewer ${OpenCV_LIBS} absl::str_format)
