cmake_minimum_required(VERSION 3.16)
project(lexer)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(lexer STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(lexer PRIVATE
    tokens
)

target_include_directories(lexer
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
