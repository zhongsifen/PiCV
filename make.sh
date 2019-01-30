mkdir -p build
cd build

cmake \
-D CMAKE_BUILD_TYPE=RELEASE \
-D CMAKE_COLOR_MAKEFILE=OFF \
-D CMAKE_INSTALL_PREFIX=./install \
-D CMAKE_CXX_FLAGS="-std=c++11" \
..

make
