cmake_minimum_required(VERSION 3.1.5)

project(box CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -mwindows -Wall ")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -m3dnow -Wall ")
set(CMAKE_BUILD_TYPE RELEASE)

#include_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.5/i686-w64-mingw32/include)
#include_directories(C:/Users/liubailin/SDL2/SDL2-2.0.9/i686-w64-mingw32/include/)
#include_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.5/i686-w64-mingw32/include/SDL2)
#include_directories(C:/Users/liubailin/SDL2/SDL2-2.0.9/i686-w64-mingw32/include/SDL2)

#link_directories(C:/Users/liubailin/SDL2/SDL2-2.0.9/i686-w64-mingw32/lib)
#link_directories(C:/Users/liubailin/SDL2/SDL2_image-2.0.5/i686-w64-mingw32/lib)


add_subdirectory(src)
add_subdirectory(Test)
add_subdirectory(SDLdraw)

link_libraries(box_main)
link_libraries(sdldraw)

#link_libraries(mingw32 SDL2main SDL2 SDL2_image)

link_libraries(SDL2 SDL2_image)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/output)
add_executable(box main.cpp adapt.cpp)
