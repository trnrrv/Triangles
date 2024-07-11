cmake_minimum_required(VERSION 3.0.0) 

project(Triangles CXX)
#set(CMAKE_C_COMPILER /usr/bin) 
#set(PROJECT_NAME Triangles)
#set(CMAKE_CXX_COMPILER /usr/bin)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

file(GLOB CPP_SOURCES "./*.cpp")
include_directories("${PROJECT_SOURCE_DIR}/")
add_executable(${PROJECT_NAME} ${CPP_SOURCES})
