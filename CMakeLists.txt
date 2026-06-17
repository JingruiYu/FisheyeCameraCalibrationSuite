cmake_minimum_required(VERSION 2.8)
project(fisheye_camera_calibration_suite)

find_package(OpenCV REQUIRED)

add_executable(fisheye_calibrate fisheye_calibrate.cpp)
target_link_libraries(fisheye_calibrate ${OpenCV_LIBS})

add_executable(camera_calibrate camera_calibrate.cpp)
target_link_libraries(camera_calibrate ${OpenCV_LIBS})
