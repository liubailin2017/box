cmake_minimum_required(VERSION 3.1.5)
project(box CXX)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
include_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.5/i686-w64-mingw32/include/)
include_directories(C:/Users/liubailin/SDL2/SDL2-2.0.9/i686-w64-mingw32/include/)


include_directories(../SDLC)
include_directories(../SDLC/Extends)

link_libraries(SDLC)
link_libraries(mingw32 SDL2main SDL2 SDL2_image)

add_executable(palettetest palettetest.cpp)
add_executable(pngtest pngtest.cpp)
add_executable(testsdlc testSDLC.cpp)