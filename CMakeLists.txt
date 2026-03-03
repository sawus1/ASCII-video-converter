cmake_minimum_required(VERSION 3.16)
project(ascii-video)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(ascii-video main.cpp ${SOURCES})

target_include_directories(ascii-video PRIVATE include)

target_link_libraries(ascii-video ${OpenCV_LIBS})