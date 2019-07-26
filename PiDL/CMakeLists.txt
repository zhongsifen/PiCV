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

set(OPENCV_DIR ${CMAKE_SOURCE_DIR}/../minicv/install)
set(DLIB_DIR   ${CMAKE_SOURCE_DIR}/../minicv/install)

target_include_directories(PiDL PUBLIC
	${CMAKE_SOURCE_DIR}
	${OPENCV_DIR}/include/opencv4
	${DLIB_DIR}/include
)

target_link_libraries(PiDL LINK_PUBLIC
	PiCV
	${DLIB_DIR}/lib/libdlib.a
	libblas.dylib
	liblapack.dylib
)
