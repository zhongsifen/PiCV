add_library(PiCV SHARED
    PiCV.cpp
    PiCV.hpp
)

target_include_directories(PiCV PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
