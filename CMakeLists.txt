cmake_minimum_required(VERSION 3.26)
project(2D_game_assignment)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

configure_file(resources/background.png ${CMAKE_CURRENT_BINARY_DIR}/resources/background.png COPYONLY)
configure_file(resources/pacman.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman.png COPYONLY)
configure_file(resources/ghost.png ${CMAKE_CURRENT_BINARY_DIR}/resources/ghost.png COPYONLY)

add_executable(2D_game_assignment
        src/main.cpp
        src/game.cpp)

target_include_directories(2D_game_assignment PRIVATE ${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

# Manually specify the SFML libraries
set(SFML_LIBRARIES
        sfml-graphics
        sfml-window
        sfml-system
)

target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})

add_subdirectory(Google_tests)