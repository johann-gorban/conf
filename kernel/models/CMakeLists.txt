cmake_minimum_required(VERSION 3.16)
project(models)

set(CMAKE_CXX_STANDARD 14)

# Создаем виртуальную include-директорию
file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/models_include/models)

# Создаем симлинки для заголовочных файлов
add_custom_command(
    OUTPUT 
        ${CMAKE_CURRENT_BINARY_DIR}/models_include/models/context.hpp
        ${CMAKE_CURRENT_BINARY_DIR}/models_include/models/token.hpp
    COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_CURRENT_SOURCE_DIR}/context/include/context.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/models_include/models/context.hpp
    COMMAND ${CMAKE_COMMAND} -E create_symlink
            ${CMAKE_CURRENT_SOURCE_DIR}/token/include/token.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/models_include/models/token.hpp
    DEPENDS 
        ${CMAKE_CURRENT_SOURCE_DIR}/context/include/context.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/token/include/token.hpp
)

add_custom_target(models_symlinks ALL
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/models_include/models/context.hpp
            ${CMAKE_CURRENT_BINARY_DIR}/models_include/models/token.hpp
)

add_subdirectory(token)
add_subdirectory(context)

# INTERFACE-библиотека для группировки
add_library(models INTERFACE)
add_dependencies(models models_symlinks)

# Подключаем виртуальную директорию
target_include_directories(models INTERFACE
    ${CMAKE_CURRENT_BINARY_DIR}/models_include
)

target_link_libraries(models INTERFACE  
    context
    token
)