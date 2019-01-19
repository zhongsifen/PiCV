add_library(PiCV SHARED
    PiCV.cpp
    PiCV.hpp
    _PiCV.cpp
    _PiCV.hpp
)
set_target_properties(PiCV PROPERTIES
    SUFFIX .so
)

target_include_directories(PiCV PUBLIC
    ${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(PiCV LINK_PUBLIC
    ${CMAKE_SOURCE_DIR}/opencv/build/lib/libopencv_core.dylib
    ${CMAKE_SOURCE_DIR}/opencv/build/lib/libopencv_imgproc.dylib
    ${CMAKE_SOURCE_DIR}/opencv/build/lib/libopencv_highgui.dylib
    ${CMAKE_SOURCE_DIR}/opencv/build/lib/libopencv_videoio.dylib
)
