cmake_minimum_required(VERSION 3.20)

project(bench)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

set(BENCHMARK_ENABLE_TESTING OFF)
FetchContent_Declare(benchmark
    GIT_REPOSITORY https://github.com/google/benchmark
    GIT_TAG 3fd1e6a
    GIT_SHALLOW ON
)

FetchContent_MakeAvailable(benchmark)

add_executable(bench main.cpp)
target_link_libraries(bench PUBLIC benchmark)
