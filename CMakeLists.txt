cmake_minimum_required(VERSION 3.16)
project(conf CXX)

option(ENABLE_TESTS "Build tests executable" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/config
    ${CMAKE_CURRENT_SOURCE_DIR}/preprocessor
    ${CMAKE_CURRENT_SOURCE_DIR}/property
)

file(GLOB SOURCES
    config/*.cpp
    preprocessor/*.cpp
    property/*.cpp
)

if(ENABLE_TESTS)
    message(STATUS "Building tests...")

    file(GLOB TEST_SOURCES 
        tests/*.cpp
    )

    add_executable(conf_test
        ${SOURCES}
        ${TEST_SOURCES}
    )
else()
    add_library(conf STATIC ${SOURCES})
endif()
