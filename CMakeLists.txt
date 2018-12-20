cmake_minimum_required(VERSION 3.12)
project(graphics)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")

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

add_executable(viewer viewer.cpp)
add_subdirectory(efsw)
set(STATIC_LIB ON)
set(BOOST_ROOT "/Users/blanders/.brew")
find_package(Boost 1.68.0 COMPONENTS system filesystem REQUIRED)

include_directories(viewer efsw/include)
include_directories(viewer ${Boost_INCLUDE_DIRS})
target_link_libraries(viewer ${OpenCV_LIBS} efsw ${Boost_LIBRARIES})

# Timer library and test

add_library(timer SHARED Timer.h)
set_target_properties(timer PROPERTIES LINKER_LANGUAGE CXX)

add_executable(timer_unittest Timer_unittest.cpp)
target_link_libraries(timer_unittest timer)
target_link_libraries(timer_unittest gtest gtest_main)

# Tuple

add_library(tuple SHARED Tuple.h)
set_target_properties(tuple PROPERTIES LINKER_LANGUAGE CXX)

# Vector3 and test

add_library(vector3 SHARED Vector3.h)
set_target_properties(vector3 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(vector3 tuple)

add_executable(vector3_unittest Vector3_unittest.cpp)
target_link_libraries(vector3_unittest vector3)
target_link_libraries(vector3_unittest gtest gtest_main)

# Color and test

add_library(color SHARED Color.h)
set_target_properties(color PROPERTIES LINKER_LANGUAGE CXX)

add_executable(color_unittest Color_unittest.cpp)
target_link_libraries(color_unittest color)
target_link_libraries(color_unittest gtest gtest_main)

# Canvas and test

add_library(canvas SHARED Canvas.h)
set_target_properties(canvas PROPERTIES LINKER_LANGUAGE CXX)

add_executable(canvas_unittest Canvas_unittest.cpp)
target_link_libraries(canvas_unittest canvas absl::base absl::str_format)
target_link_libraries(canvas_unittest gtest gtest_main)

# Matrix and test

add_library(matrix SHARED Matrix.h)
set_target_properties(matrix PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(matrix vector3)

add_executable(matrix_unittest Matrix_unittest.cpp Matrix.h)
target_link_libraries(matrix_unittest matrix absl::base absl::str_format)
target_link_libraries(matrix_unittest gtest gtest_main)