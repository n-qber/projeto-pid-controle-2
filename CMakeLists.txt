cmake_minimum_required(VERSION 3.22)
project(wall-e)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SOURCES "src/*.cpp")

add_executable(wall-e ${SOURCES})

target_include_directories(wall-e PUBLIC include)