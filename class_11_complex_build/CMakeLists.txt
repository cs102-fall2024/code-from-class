#minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

#project name and version
project(CatProject VERSION 1.0)

#What C++ version were' making
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_STANDARD_REQUIRED True)

#add execiuutable target with source files
add_executable(CatProgram src/main.cpp src/Cat.cpp)