cmake_minimum_required(VERSION 3.16)
project(processing)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/lexer/source/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/parser/source/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processor/source/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/source/*.cpp
)

file(GLOB HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/lexer/include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/parser/include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/processor/include/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/utils/include/*.hpp
)

add_library(processing STATIC
    ${SOURCES}
)

target_include_directories(processing
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)