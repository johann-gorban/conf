cmake_minimum_required(VERSION 3.16)
project(kernel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(models)
add_subdirectory(lexer)