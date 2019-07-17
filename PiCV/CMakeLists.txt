add_library(PiCV SHARED
    PiCV.cpp
    PiCV.hpp
    ctypes.cpp
    ctypes.hpp
)
set_target_properties(PiCV PROPERTIES
    SUFFIX .so
)

set(OPENCV_DIR "/home/zhongsifen/Work/minicv/install")

target_include_directories(PiCV PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${OPENCV_DIR}/include/opencv4
)

target_link_libraries(PiCV LINK_PUBLIC
    ${OPENCV_DIR}/lib/libopencv_core.so
    ${OPENCV_DIR}/lib/libopencv_imgproc.so
    ${OPENCV_DIR}/lib/libopencv_highgui.so
    ${OPENCV_DIR}/lib/libopencv_videoio.so
)
