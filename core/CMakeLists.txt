cmake_minimum_required(VERSION 3.16)
project(conf)

set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/*/source/*.cpp
)

file(GLOB_RECURSE HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/*/include/*.hpp
)

add_library(conf STATIC
    ${SOURCES}
    ${HEADERS}
)

target_include_directories(conf
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/config/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/lexer/include
        ${CMAKE_CURRENT_SOURCE_DIR}/parser/include
        ${CMAKE_CURRENT_SOURCE_DIR}/processor/include
        ${CMAKE_CURRENT_SOURCE_DIR}/token/include
)