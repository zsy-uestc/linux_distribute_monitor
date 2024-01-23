#!/usr/bin/env bash

# 脚本在任何命令出错（返回非零退出状态码）时立即停止执行。并且不会继续执行后续的命令。
set -e

cd "$(dirname "${BASH_SOURCE[0]}")"

# https://github.com/abseil/abseil-cpp/archive/refs/tags/20200225.2.tar.gz
# Install abseil.
THREAD_NUM=$(nproc)
VERSION="20200225.2"
PKG_NAME="abseil-cpp-${VERSION}.tar.gz"

tar xzf "${PKG_NAME}"
pushd "abseil-cpp-${VERSION}"
    mkdir build && cd build
    cmake .. \
        -DBUILD_SHARED_LIBS=ON \
        -DCMAKE_CXX_STANDARD=14 \
        -DCMAKE_INSTALL_PREFIX=/usr/local
    make -j${THREAD_NUM}
    make install
popd

ldconfig

# Clean up
rm -rf "abseil-cpp-${VERSION}" "${PKG_NAME}"