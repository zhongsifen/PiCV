add_executable(appPiCV
    main.cpp
)

target_include_directories(appPiCV PUBLIC
	${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/opencv/build/install/include/opencv4
)

target_link_libraries(appPiCV LINK_PUBLIC
     PiCV
)
