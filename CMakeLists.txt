cmake_minimum_required(VERSION 3.1.5)

project(box CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Wall -g")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -mwindows -Wall ")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -m3dnow -Wall ")
set(CMAKE_BUILD_TYPE DEBUG)

include_directories(D:/lib/SDL2_image-2.0.5/i686-w64-mingw32/include)
include_directories(D:/lib/SDL2-2.0.10/i686-w64-mingw32/include)
include_directories(D:/lib/SDL2-2.0.10/i686-w64-mingw32/include/SDL2)
include_directories(D:/lib/SDL2_ttf/i686-w64-mingw32/include)

link_directories(D:/lib/SDL2-2.0.10/i686-w64-mingw32/lib)
link_directories(D:/lib/SDL2_image-2.0.5/i686-w64-mingw32/lib)
link_directories(D:/lib/SDL2_ttf/i686-w64-mingw32/lib)


add_subdirectory(Box)
add_subdirectory(Test)
add_subdirectory(SDLdraw)
add_subdirectory(SDLC)

link_libraries(box_main)
link_libraries(sdldraw)
link_libraries(SDLC)

link_libraries(mingw32 SDL2main SDL2 SDL2_image SDL2_ttf)

file(GLOB_RECURSE Box_source  main.cpp  mainhand.cpp bfs.cpp snakehand.cpp menu_event.cpp edithand.cpp GlobalData.cpp)

#link_libraries(SDL2 SDL2_image)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/output)

add_executable(box ${Box_source})
