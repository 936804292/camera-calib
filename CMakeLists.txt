cmake_minimum_required(VERSION 2.8.3)
project(camera_calibration)

add_compile_options(-std=c++11)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenCV REQUIRED)

SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}/usr/local/lib/cmake)
find_package(raspicam REQUIRED)

add_executable(camera_calibration camera_calibration.cpp)

target_link_libraries(camera_calibration
  ${OpenCV_LIBS}
  ${raspicam_CV_LIBS}
)
