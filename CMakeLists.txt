cmake_minimum_required(VERSION 3.26)
project(2D_game_assignment)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

configure_file(resources/background.png ${CMAKE_CURRENT_BINARY_DIR}/resources/background.png COPYONLY)
configure_file(resources/pacman.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman.png COPYONLY)
configure_file(resources/ghost.png ${CMAKE_CURRENT_BINARY_DIR}/resources/ghost.png COPYONLY)

set(SFML_INCLUDE_DIR "C:/SFML-2.6.1/include")
set(SFML_LIBRARY_DIR "C:/SFML-2.6.1/lib")

add_executable(2D_game_assignment
        src/main.cpp
        src/game.cpp)

target_include_directories(2D_game_assignment PRIVATE ${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

# Manually specify the SFML libraries
set(SFML_LIBRARIES
        "${SFML_LIBRARY_DIR}/libsfml-graphics.a"
        "${SFML_LIBRARY_DIR}/libsfml-window.a"
        "${SFML_LIBRARY_DIR}/libsfml-system.a"
)

target_link_libraries(2D_game_assignment ${SFML_LIBRARIES})