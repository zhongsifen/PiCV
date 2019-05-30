add_library(PiCV SHARED
    PiCV.cpp
    PiCV.hpp
    ctypes.cpp
    ctypes.hpp
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
    /Users/zhongsifen/Work/opencv/build/install/lib/libopencv_core.dylib
    /Users/zhongsifen/Work/opencv/build/install/lib/libopencv_imgproc.dylib
    /Users/zhongsifen/Work/opencv/build/install/lib/libopencv_highgui.dylib
    /Users/zhongsifen/Work/opencv/build/install/lib/libopencv_videoio.dylib
)
