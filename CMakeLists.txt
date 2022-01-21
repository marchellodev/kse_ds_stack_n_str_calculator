cmake_minimum_required(VERSION 3.21)
project(kse_alg_1)

set(CMAKE_CXX_STANDARD 23)

#include_directories(/usr/include/readline)
set(CMAKE_CXX_FLAGS "-L/usr/local/lib -I/usr/local/include -lreadline")

# GOOGLE TEST
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(kse_alg_1 src/main.cpp src/lib/Stack.ipp src/lib/Stack.h src/Token.cpp)

enable_testing()

add_executable(
        testing
        testing.cpp
)
target_link_libraries(
        testing
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(testing)

