cmake_minimum_required(VERSION 3.28)
project(untitled)


set(CMAKE_CXX_STANDARD 17)
link_directories(/opt/homebrew/Cellar/raylib/5.0/lib)

add_executable(untitled main.cpp
        cell.h
        cell.cpp)
# Link raylib library
target_link_libraries(untitled raylib)
