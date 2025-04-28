cmake_minimum_required(VERSION 3.10)

project(SortingAlgos C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)

add_compile_options(-Wall -Wextra)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

add_library(utils STATIC src/utils.c)

set(COMPILING_FILE "src/quickSort.c")

get_filename_component(EXECUTABLE_NAME ${COMPILING_FILE} NAME_WE)
add_executable(${EXECUTABLE_NAME} ${COMPILING_FILE})

target_link_libraries(${EXECUTABLE_NAME} utils)

add_custom_command(TARGET ${EXECUTABLE_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo "Running ${EXECUTABLE_NAME}..."
    COMMAND $<TARGET_FILE:${EXECUTABLE_NAME}>
)