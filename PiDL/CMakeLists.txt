add_library(PiDL SHARED
	PiDL.cpp
	PiDL.hpp
	PiDLConfig.hpp
	dlib_anet.hpp
	dlib_cv.hpp
)

target_include_directories(PiDL PUBLIC
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(PiDL LINK_PUBLIC
	dlib
	PiCV
	${CMAKE_SOURCE_DIR}/lib/libopencv_core.4.0.0.dylib
	${CMAKE_SOURCE_DIR}/lib/libopencv_imgproc.4.0.0.dylib
	${CMAKE_SOURCE_DIR}/lib/libopencv_highgui.4.0.0.dylib
	${CMAKE_SOURCE_DIR}/lib/libopencv_videoio.4.0.0.dylib
)
