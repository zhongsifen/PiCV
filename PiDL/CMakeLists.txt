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
	${CMAKE_SOURCE_DIR}/dlib/build/install/lib/libdlib.a
	${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_core.so
	${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_imgproc.so
	${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_highgui.so
	${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_videoio.so
	/usr/lib/libcblas.so
	/usr/lib/liblapack.so
)
