cmake_minimum_required(VERSION 3.16)
project(token)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(token STATIC
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(token
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)