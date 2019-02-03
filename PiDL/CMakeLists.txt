add_library(PiDL SHARED
	PiDL.cpp
	PiDL.hpp
	PiDLConfig.hpp
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
#	dlib
	${CMAKE_SOURCE_DIR}/dlib/build/install/lib/libdlib.a
	${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_core.dylib
    ${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_imgproc.dylib
    ${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_highgui.dylib
	${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_videoio.dylib
	/usr/lib/libcblas.dylib
    /usr/lib/liblapack.dylib

)
