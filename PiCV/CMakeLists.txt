add_library(PiCV SHARED
    PiCV.cpp
    PiCV.hpp
    _PiCV.cpp
    _PiCV.hpp
)

target_include_directories(PiCV PUBLIC
    ${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(PiCV LINK_PUBLIC
#    ${CMAKE_SOURCE_DIR}/lib/libopencv_core.a
    ${CMAKE_SOURCE_DIR}/lib/libopencv_core.4.0.0.dylib
    ${CMAKE_SOURCE_DIR}/lib/libopencv_imgproc.4.0.0.dylib
    ${CMAKE_SOURCE_DIR}/lib/libopencv_highgui.4.0.0.dylib
    ${CMAKE_SOURCE_DIR}/lib/libopencv_videoio.4.0.0.dylib
#    /usr/local/opt/lapack/lib/liblapack.dylib
#    ${CMAKE_SOURCE_DIR}/lib/libippicv.a
#    ${CMAKE_SOURCE_DIR}/lib/libzlib.a
)
