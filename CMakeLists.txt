cmake_minimum_required(VERSION 3.12)
project(graphics)

set(CMAKE_CXX_STANDARD 14)

# -------- Google Test

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(gtest_smoketest gtest_smoketest.cpp)
target_link_libraries(gtest_smoketest gtest gtest_main)

# -------- OpenCV

set(CMAKE_PREFIX_PATH /Users/blanders/src/external/opencv-4.0.0/build)
find_package(OpenCV REQUIRED)

# -------- Google ABSL

add_subdirectory(abseil-cpp)

# -------- viewer

add_executable(viewer viewer/viewer.cpp)
target_link_libraries(viewer ${OpenCV_LIBS})
