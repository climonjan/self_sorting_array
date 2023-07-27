cmake_minimum_required(VERSION 3.16.3)

project(CALCULATOR)

set(CMAKE_CXX_STANDARD 17)
set(SOURCES *.cpp)
set(TARGET main)

add_executable(${TARGET} ${SOURCES})

target_include_directories(${TARGET} PRIVATE ".")