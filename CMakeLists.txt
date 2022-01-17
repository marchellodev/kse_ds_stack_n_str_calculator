cmake_minimum_required(VERSION 3.21)
project(kse_alg_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(kse_alg_1 src/main.cpp src/lib/Stack.ipp src/lib/Stack.h src/Token.cpp)
