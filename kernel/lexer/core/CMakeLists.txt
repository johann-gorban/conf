cmake_minimum_required(VERSION 3.16)
project(lexer-core)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(lexer-core STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(lexer-core PRIVATE
    lexer-states
    models
)

target_include_directories(lexer-core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
