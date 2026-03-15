cmake_minimum_required(VERSION 3.16)

project(PathFinding
    VERSION 1.0
    DESCRIPTION "Pathfinding algorithms project by Pieczywosoleckie"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



file(GLOB_RECURSE PATHFINDING_SOURCES
    pathfinding-cpp/src/*.cpp
)


add_library(pathfinding ${PATHFINDING_SOURCES})

target_include_directories(pathfinding
    PUBLIC
        ${PROJECT_SOURCE_DIR}/pathfinding-cpp/include
)

if (MSVC)
    target_compile_options(pathfinding
        PRIVATE
        /W4
    )
else()
    target_compile_options(pathfinding
        PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()

add_executable(pathfinding_app
    pathfinding-cpp/src/main.cpp
)

target_link_libraries(pathfinding_app
    PRIVATE pathfinding
)


enable_testing()

file(GLOB TEST_SOURCES
    tests/*.cpp
)

if(TEST_SOURCES)
    add_executable(pathfinding_tests
        ${TEST_SOURCES}
    )

    target_link_libraries(pathfinding_tests
        PRIVATE pathfinding
    )

    add_test(
        NAME pathfinding_tests
        COMMAND pathfinding_tests
    )
endif()