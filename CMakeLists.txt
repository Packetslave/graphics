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
add_subdirectory(efsw)
set(STATIC_LIB ON)
set(BOOST_ROOT "/Users/blanders/.brew")
find_package(Boost 1.68.0 COMPONENTS system filesystem REQUIRED)

include_directories(viewer efsw/include)
include_directories(viewer ${Boost_INCLUDE_DIRS})
target_link_libraries(viewer ${OpenCV_LIBS} efsw ${Boost_LIBRARIES})

# -------- pragprog

add_library(
        pragprog_raytracing
        pragprog_raytracing/Vector3.cpp pragprog_raytracing/Vector3.h
)

add_executable(pragprog_raytracing_tests pragprog_raytracing/Vector3_unittest.cpp)
target_link_libraries(pragprog_raytracing_tests gtest gtest_main)
target_link_libraries(pragprog_raytracing_tests pragprog_raytracing)