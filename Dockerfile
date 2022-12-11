FROM gcc:12.2.0 as install
RUN apt-get update && \
    apt-get -y install cmake protobuf-compiler libgtest-dev
RUN cd /usr/src/gtest && \
    cmake . && make && \
    cp lib/*.a /usr/lib && \
    mkdir -p /usr/local/lib/gtest && \
    ln -s /usr/lib/libgtest.a /usr/local/lib/gtest/libgtest.a && \
    ln -s /usr/lib/libgtest_main.a /usr/local/lib/gtest/libgtest_main.a

FROM install as C
COPY libs/C /usr/src/zeta-filter
WORKDIR /usr/src/zeta-filter

FROM C as C-test
RUN mkdir build && \
    cd build && \
    cmake .. && \
    make && \
    ./test --gtest_shuffle
