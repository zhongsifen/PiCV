add_library(PiDL SHARED
	PiDL.cpp
	PiDLConfig.hpp
	PiDL.hpp
	_PiDL.hpp
	dlib_anet.hpp
	dlib_cv.hpp
)
set_target_properties(PiDL PROPERTIES
    SUFFIX .so
)

target_include_directories(PiDL PUBLIC
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/opencv/build/install/include/opencv4
	${CMAKE_SOURCE_DIR}/dlib/build/install/include
)

target_link_libraries(PiDL LINK_PUBLIC
	PiCV
	${CMAKE_SOURCE_DIR}/lib/libopencv_core.4.0.0.so
	${CMAKE_SOURCE_DIR}/lib/libopencv_imgproc.4.0.0.so
	${CMAKE_SOURCE_DIR}/lib/libopencv_highgui.4.0.0.so
	${CMAKE_SOURCE_DIR}/lib/libopencv_videoio.4.0.0.so
)
