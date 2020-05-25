cmake_minimum_required(VERSION 3.1.5)

project(box C)

set(CMAKE_VERBOSE_MAKEFILE ON)

#include_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.5/i686-w64-mingw32/include/)
#include_directories(C:/Users/liubailin/SDL2/SDL2-2.0.9/i686-w64-mingw32/include/)

file(GLOB_RECURSE code_sources "./*.c")


add_library(fini ${code_sources})
