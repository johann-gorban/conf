cmake_minimum_required(VERSION 3.16)
project(lexer)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(states)
add_subdirectory(core)

add_library(lexer INTERFACE)

target_link_libraries(lexer INTERFACE
    models
)

target_include_directories(lexer
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/core/include
)
