cmake_minimum_required(VERSION 3.1.5)

project(box CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(D:/lib/SDL2_image-2.0.5/i686-w64-mingw32/include)
include_directories(D:/lib/SDL2-2.0.10/i686-w64-mingw32/include)
include_directories(D:/lib/SDL2_image-2.0.5/i686-w64-mingw32/include/SDL2)
include_directories(D:/lib/SDL2-2.0.10/i686-w64-mingw32/include/SDL2)


file(GLOB_RECURSE code_sources "./*.cpp")

add_library(sdldraw ${code_sources})
