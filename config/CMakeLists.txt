cmake_minimum_required(VERSION 3.16)
project(config)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(config STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(config PRIVATE
    kernel
)

target_include_directories(config
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)