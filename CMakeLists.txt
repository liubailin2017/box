cmake_minimum_required(VERSION 3.1.5)
project(box CXX)
#include_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.1/x86_64-w64-mingw32/include/SDL2/)
#include_directories(C:/Users/liubailin/SDL2/SDL2-2.0.5/x86_64-w64-mingw32/include/SDL2/)

#link_directories(C:/Users/liubailin/SDL2/SDL2-2.0.5/x86_64-w64-mingw32/lib/)
#link_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.1/x86_64-w64-mingw32/lib/)
#link_libraries(SDL2main)  

add_subdirectory(src)
add_subdirectory(Test)
add_subdirectory(SDLdraw)

link_libraries(SDL2)
link_libraries(SDL2_image)
link_libraries(main)
link_libraries(sdldraw)

add_executable(box  main.cpp adapt.cpp)
