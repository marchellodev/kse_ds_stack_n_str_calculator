cmake_minimum_required(VERSION 3.21)
project(kse_stack)

set(CMAKE_CXX_STANDARD 23)

add_executable(kse_stack main.cpp lib/Stack.ipp lib/Stack.h tokenization.cpp)
