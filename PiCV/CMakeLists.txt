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
    /home/pi/Work/opencv-4.0.1/build/lib/libopencv_core.so
    /home/pi/Work/opencv-4.0.1/build/lib/libopencv_imgproc.so
    /home/pi/Work/opencv-4.0.1/build/lib/libopencv_highgui.so
    /home/pi/Work/opencv-4.0.1/build/lib/libopencv_videoio.so
)
