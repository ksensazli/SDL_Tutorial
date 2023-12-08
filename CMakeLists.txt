cmake_minimum_required(VERSION 3.5)

project(SDL_Tutorial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SDL_Tutorial main.cpp
    sample.bmp
    button.bmp
    example.wav
)

include(GNUInstallDirs)
install(TARGETS SDL_Tutorial
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(SDL_Tutorial ${SDL2_LIBRARIES})

set_target_properties(SDL_Tutorial PROPERTIES
        BUILD_RPATH "/Library/Frameworks"
        INSTALL_RPATH "/Library/Frameworks"
)

