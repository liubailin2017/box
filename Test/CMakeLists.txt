cmake_minimum_required(VERSION 3.1.5)
project(box)
#include_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.1/x86_64-w64-mingw32/include/SDL2/)
#include_directories(C:/Users/liubailin/SDL2/SDL2-2.0.5/x86_64-w64-mingw32/include/SDL2/)

#link_directories(C:/Users/liubailin/SDL2/SDL2-2.0.5/x86_64-w64-mingw32/lib/)
#link_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.1/x86_64-w64-mingw32/lib/)
#link_libraries(SDL2main)
 
link_libraries(SDL2)
link_libraries(SDL2_image)
link_libraries(sdldraw)

add_executable(palettetest palettetest.cpp)
