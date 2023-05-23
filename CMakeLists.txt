cmake_minimum_required(VERSION 3.20)
project(file-manager)


include_directories(include)
file(GLOB SOURCES src/*.cpp)
add_executable(file-manager ${SOURCES})