cmake_minimum_required(VERSION 3.5)
SET(CMAKE_TOOLCHAIN_FILE "c:/vcpkg/scripts/buildsystems/vcpkg.cmake")
project(box CXX)
set(CMAKE_BUILD_TYPE DEBUG)
set(CMAKE_VERBOSE_MAKEFILE ON)
# SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Wall -g")
# SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -mwindows -Wall ")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -m3dnow -Wall ")

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)

IF (CMAKE_SYSTEM_NAME MATCHES "Windows")
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
ENDIF()

add_subdirectory(fini)
add_subdirectory(Box)
# add_subdirectory(Test)
add_subdirectory(SDLdraw)
add_subdirectory(SDLC)

# link_libraries(fini)
# link_libraries(box_main)
# link_libraries(sdldraw)
# link_libraries(SDLC)
file(GLOB_RECURSE Box_source  main.cpp  mainhand.cpp bfs.cpp snakehand.cpp menu_event.cpp edithand.cpp GlobalData.cpp)

add_executable(box ${Box_source} 
#icon.o
)


target_link_libraries( box
    PRIVATE SDLC 
    PRIVATE fini
    PRIVATE box_main
    PRIVATE sdldraw
    PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> 
    PRIVATE $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>
    PRIVATE $<IF:$<TARGET_EXISTS:SDL2_ttf::SDL2_ttf>,SDL2_ttf::SDL2_ttf,SDL2_ttf::SDL2_ttf-static>
)

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/output)


