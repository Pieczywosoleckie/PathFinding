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

add_custom_command(TARGET pathfinding_app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${PROJECT_SOURCE_DIR}/map.txt
        $<TARGET_FILE_DIR:pathfinding_app>
)

enable_testing()

file(GLOB TEST_SOURCES
    ${PROJECT_SOURCE_DIR}/tests/*.cpp
)

if(TEST_SOURCES)
    add_executable(pathfinding_tests
        ${TEST_SOURCES}
    )

    target_link_libraries(pathfinding_tests
        PRIVATE pathfinding
    )

    target_include_directories(pathfinding_tests
        PRIVATE ${PROJECT_SOURCE_DIR}/pathfinding-cpp/include
    )

    add_custom_command(TARGET pathfinding_tests POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${PROJECT_SOURCE_DIR}/map.txt
            $<TARGET_FILE_DIR:pathfinding_tests>
    )

    add_test(
        NAME pathfinding_tests
        COMMAND pathfinding_tests
    )
endif()