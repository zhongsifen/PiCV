add_executable(appPiDL
    main.cpp
)

target_include_directories(appPiDL PUBLIC
	${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/opencv/build/install/include/opencv4
    ${CMAKE_SOURCE_DIR}/dlib/build/install/include
)

target_link_libraries(appPiDL LINK_PUBLIC
     PiDL
)
