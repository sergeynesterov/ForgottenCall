FROM runtime_environment

RUN apk add --no-cache ninja cmake g++ gtest gtest-dev boost-dev git && \
    git clone https://github.com/GENIVI/dlt-daemon.git && git -C ./dlt-daemon checkout tags/v2.18.0 -b v2.18.0 && \
    CFLAGS="-include pthread.h" cmake -S ./dlt-daemon -B ./dlt-daemon/build -GNinja \
    -DBUILD_SHARED_LIBS=OFF -DWITH_DLT_CONSOLE=OFF -DWITH_DLT_EXAMPLES=OFF -DWITH_DLT_TESTS=OFF -DWITH_DLT_USE_IPv6=OFF && \
    cmake --build ./dlt-daemon/build --target install && \
    rm -rf ./dlt-daemon && apk del --purge --rdepends git