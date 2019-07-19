cmake_minimum_required(VERSION 3.5.1)
project(PiCV)

set(CMAKE_CXX_FLAGS, "-std=c++11")

#add_subdirectory(opencv)
#add_subdirectory(dlib)
add_subdirectory(PiCV)
add_subdirectory(PiDL)
add_subdirectory(appPiCV)
#add_subdirectory(appPiDL)
