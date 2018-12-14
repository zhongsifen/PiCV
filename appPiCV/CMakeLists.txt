add_executable(appPiCV
    main.cpp
)

#include_directories(
#	${CMAKE_SOURCE_DIR}
#)

target_include_directories(appPiCV PUBLIC
	${CMAKE_SOURCE_DIR}
)

target_link_libraries(appPiCV LINK_PUBLIC
     PiCV
) 
