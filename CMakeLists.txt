cmake_minimum_required(VERSION 3.16)
project(file-manager)

set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)

link_libraries(stdc++fs)
include_directories(include)
file(GLOB SOURCES src/*.cpp)
add_executable(file-manager ${SOURCES})
