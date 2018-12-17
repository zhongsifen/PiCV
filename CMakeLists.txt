cmake_minimum_required (VERSION 3.0.0)
project (PiCV)

add_subdirectory (PiCV)
add_subdirectory (appPiCV)

include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/include
)
