cmake_minimum_required(VERSION 3.16)
project(context)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(context STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(context
    PUBLIC
        token
)

target_include_directories(context
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)