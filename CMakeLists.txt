cmake_minimum_required(VERSION 3.5.1)
project(PiCV)

set(CMAKE_CXX_FLAGS, "-std=c++11")

set(OPENCV_DIR ${CMAKE_SOURCE_DIR}/../minicv/install)
set(DLIB_DIR   ${CMAKE_SOURCE_DIR}/../minidl/install)

add_subdirectory(PiCV)
add_subdirectory(PiDL)
add_subdirectory(appPiCV)
add_subdirectory(appPiDL)
