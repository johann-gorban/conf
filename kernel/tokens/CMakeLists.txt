cmake_minimum_required(VERSION 3.16)
project(tokens)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(tokens STATIC
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(tokens
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)