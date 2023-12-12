cmake_minimum_required(VERSION 3.26)
project(Google_tests)

# Include the directories for SFML
include_directories(${SFML_INCLUDE_DIR})

# Add Google Test
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add your test executable
add_executable(Google_Tests_run test1.cpp
        ../include/game.h
        ../src/game.cpp)

# Link Google Test and SFML libraries
target_link_libraries(Google_Tests_run gtest gtest_main ${SFML_LIBRARIES})

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../resources/background.png ${CMAKE_CURRENT_BINARY_DIR}/resources/background.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../resources/pacman.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman.png COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/../resources/ghost.png ${CMAKE_CURRENT_BINARY_DIR}/resources/ghost.png COPYONLY)