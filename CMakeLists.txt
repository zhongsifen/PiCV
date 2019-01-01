cmake_minimum_required(VERSION 3.5.1)
project(PiCV)

add_subdirectory(opencv/core)
add_subdirectory(dlib)
add_subdirectory(PiCV)
add_subdirectory(PiDL)
add_subdirectory(appPiCV)

include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/include
)
