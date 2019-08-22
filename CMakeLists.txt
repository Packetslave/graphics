cmake_minimum_required(VERSION 3.12)
project(graphics)

set(CMAKE_CXX_STANDARD 17)
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

# -------- Eigen

set(Eigen3_DIR /Users/blanders/src/external/eigen/build/)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

# -------- viewer

add_executable(viewer src/viewer.cpp)
add_subdirectory(efsw)
set(STATIC_LIB ON)
set(BOOST_ROOT "/Users/blanders/.brew")
find_package(Boost 1.68.0 COMPONENTS system filesystem REQUIRED)

include_directories(viewer efsw/include)
include_directories(viewer ${Boost_INCLUDE_DIRS})
target_link_libraries(viewer ${OpenCV_LIBS} efsw ${Boost_LIBRARIES})

# Timer library and test

add_library(timer SHARED src/Timer.h)
set_target_properties(timer PROPERTIES LINKER_LANGUAGE CXX)

add_library(timer_unittest SHARED tests/Timer_unittest.cpp)
target_link_libraries(timer_unittest gtest timer)

add_executable(timer_unittest_main tests/Timer_unittest.cpp)
target_link_libraries(timer_unittest_main gtest_main)

# Tuple and test

add_library(tuple SHARED src/Tuple.h)
set_target_properties(tuple PROPERTIES LINKER_LANGUAGE CXX)

add_library(tuple_unittest SHARED tests/Tuple_unittest.cpp)
target_link_libraries(tuple_unittest gtest tuple)

add_executable(tuple_unittest_main tests/Tuple_unittest.cpp)
target_link_libraries(tuple_unittest_main gtest_main)

# Vector3 and test

add_library(vector3 SHARED src/Vector3.h)
set_target_properties(vector3 PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(vector3 tuple Eigen3::Eigen)

add_library(vector3_unittest SHARED tests/Vector3_unittest.cpp)
target_link_libraries(vector3_unittest gtest vector3)

add_executable(vector3_unittest_main tests/Vector3_unittest.cpp)
target_link_libraries(vector3_unittest_main gtest_main)

# Point and test

add_library(point SHARED src/Point.h)
set_target_properties(point PROPERTIES LINKER_LANGUAGE CXX)

add_library(point_unittest SHARED tests/Point_unittest.cpp)
target_link_libraries(point_unittest gtest point vector3)

add_executable(point_unittest_main tests/point_unittest.cpp)
target_link_libraries(point_unittest_main vector3 gtest_main)

# Color and test

add_library(color SHARED src/Color.h)
set_target_properties(color PROPERTIES LINKER_LANGUAGE CXX)

add_library(color_unittest SHARED tests/Color_unittest.cpp)
target_link_libraries(color_unittest gtest color)

add_library(color_unittest_main tests/Color_unittest.cpp)
target_link_libraries(color_unittest_main gtest_main)

# Canvas and test

add_library(canvas SHARED src/Canvas.h)
set_target_properties(canvas PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(canvas absl::base absl::str_format)

add_library(canvas_unittest SHARED tests/Canvas_unittest.cpp)
target_link_libraries(canvas_unittest gtest canvas)

add_executable(canvas_unittest_main tests/Canvas_unittest.cpp)
target_link_libraries(canvas_unittest_main gtest_main)

# Matrix and test

add_library(matrix SHARED src/Matrix.h)
set_target_properties(matrix PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(matrix vector3)

add_library(matrix_unittest SHARED tests/Matrix_unittest.cpp src/Matrix.h)
target_link_libraries(matrix_unittest gtest matrix absl::base absl::str_format)

add_executable(matrix_unittest_main tests/Matrix_unittest.cpp src/Matrix.h)
target_link_libraries(matrix_unittest_main gtest_main)

# Ray and test

add_library(ray SHARED src/Ray.h)
set_target_properties(ray PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(ray point vector3)

add_library(ray_unittest SHARED tests/Ray_unittest.cpp src/Ray.h)
target_link_libraries(ray_unittest gtest matrix absl::base absl::str_format)

add_executable(ray_unittest_main tests/Ray_unittest.cpp src/Ray.h)
target_link_libraries(ray_unittest_main gtest_main)

# Intersection

add_library(intersection SHARED src/Intersection.h)
set_target_properties(intersection PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(intersection ray)

# Sphere and test

add_library(sphere SHARED src/Sphere.h)
set_target_properties(sphere PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(sphere ray intersection)

add_library(sphere_unittest SHARED tests/Sphere_unittest.cpp src/sphere.h)
target_link_libraries(sphere_unittest gtest matrix absl::base absl::str_format)

add_executable(sphere_unittest_main tests/Sphere_unittest.cpp src/sphere.h)
target_link_libraries(sphere_unittest_main gtest_main)

# Sphere rendering test #1
add_executable(sphere_test1 src/Sphere_test1.cpp)
target_link_libraries(sphere_test1 sphere canvas)

# All tests

add_executable(all_tests tests/all_tests.cpp)
target_link_libraries(all_tests gtest canvas_unittest matrix_unittest color_unittest vector3_unittest timer_unittest)