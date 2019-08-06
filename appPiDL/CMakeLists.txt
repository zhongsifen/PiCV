add_executable(appPiDL
    main.cpp
)

target_include_directories(appPiDL PUBLIC
	${CMAKE_SOURCE_DIR}
	${OPENCV_DIR}/include/opencv4
	${DLIB_DIR}/include
)

target_link_libraries(appPiDL LINK_PUBLIC
    PiDL
)
