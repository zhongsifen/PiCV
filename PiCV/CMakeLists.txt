add_library(PiCV SHARED
    PiCV.cpp
    PiCV.hpp
#    _PiCV.cpp
#    _PiCV.hpp
)
set_target_properties(PiCV PROPERTIES
    SUFFIX .so
)

set(OPENCV_DIR, "/Users/zhongsifen/Work/opencv/build/install")
target_include_directories(PiCV PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${OPENCV_DIR}/include/opencv4
    /Users/zhongsifen/Work/opencv/build/install/include/opencv4
)

target_link_libraries(PiCV LINK_PUBLIC
    ${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_core.so
    ${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_imgproc.so
    ${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_highgui.so
    ${CMAKE_SOURCE_DIR}/opencv/build/install/lib/libopencv_videoio.so
)
