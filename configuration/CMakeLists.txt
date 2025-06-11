cmake_minimum_required(VERSION 3.16)
project(configuration)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/manager/source/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/value/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/manager/include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/value/include/*.hpp
)

add_library(configuration STATIC
    ${SOURCES}
)

target_include_directories(configuration
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)