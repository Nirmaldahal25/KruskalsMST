cmake_minimum_required(VERSION 3.10)

project(graph VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(./include)

set(HEADER_FILE ./include/graphs.hpp ./include/graphs.tpl ./include/grapheditor.hpp)

add_executable(${PROJECT_NAME} main.cpp ${HEADER_FILE} ${SOURCE_FILE})
