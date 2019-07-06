mkdir -p build

cmake \
-D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_CONFIGURATION_TYPES=Release \
-D CMAKE_COLOR_MAKEFILE=OFF \
-D CMAKE_INSTALL_PREFIX=./install \
-D CMAKE_CXX_FLAGS="-std=c++11" \
-D INSTALL_PYTHON_EXAMPLES=OFF \
-D CV_TRACE=OFF \
-D ENABLE_PRECOMPILED_HEADERS=OFF \
-D BUILD_SHARED_LIBS=ON \
-D BUILD_JAVA=OFF \
-D BUILD_EXAMPLES=OFF \
-D BUILD_PERF_TESTS=OFF \
-D BUILD_TESTS=OFF \
-D BUILD_JPEG=OFF \
-D BUILD_PNG=OFF \
-D BUILD_ZLIB=OFF \
-D BUILD_JASPER=OFF \
-D BUILD_TIFF=OFF \
-D BUILD_WEBP=OFF \
-D BUILD_IPP_IW=OFF \
-D BUILD_PROTOBUF=OFF \
-D BUILD_opencv_apps=OFF \
-D BUILD_opencv_calib3d=OFF \
-D BUILD_opencv_features2d=OFF \
-D BUILD_opencv_flann=OFF \
-D BUILD_opencv_gapi=OFF \
-D BUILD_opencv_ml=OFF \
-D BUILD_opencv_dnn=OFF \
-D BUILD_opencv_python2=OFF \
-D BUILD_opencv_python3=OFF \
-D BUILD_opencv_python_bindings_generator=OFF \
-D BUILD_opencv_java=OFF \
-D BUILD_opencv_java_bindings_generator=OFF \
-D BUILD_opencv_js=OFF \
-D BUILD_opencv_photo=OFF \
-D BUILD_opencv_video=OFF \
-D WITH_OPENCL=OFF \
-D WITH_FFMPEG=OFF \
-D WITH_OPENEXR=OFF \
-D WITH_1394=OFF \
-D WITH_ADE=OFF \
-D WITH_ARITH_ENC=OFF \
-D WITH_ARITH_DEC=OFF \
-D WITH_QUIRC=OFF \
-H. \
-Bbuild
