cmake_minimum_required(VERSION 3.16)
project(cppMusic)

set(CMAKE_CXX_STANDARD 14)

add_executable(cppMusic main.cpp pcm_generator.cpp pcm_generator.h)