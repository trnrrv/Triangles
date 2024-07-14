cmake_minimum_required(VERSION 3.0.0) 

project(Triangles CXX)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")

file(GLOB CPP_SOURCES "./*.cpp")

include_directories("${PROJECT_SOURCE_DIR}/geom/",
                    "${PROJECT_SOURCE_DIR}/linal/")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

add_library(LINAL SHARED linal/Matrix.cpp linal/Matrix.hpp)
add_library(GEOM SHARED geom/geom.cpp geom/geom.h)
target_link_libraries(${PROJECT_NAME} LINAL)
target_link_libraries(${PROJECT_NAME} GEOM)

