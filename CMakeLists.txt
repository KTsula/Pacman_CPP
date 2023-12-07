cmake_minimum_required(VERSION 3.25)
project(2D_game_assignment)

set(CMAKE_CXX_STANDARD 14)

# If SFML is installed in a non-standard location, you might need to set SFML_DIR to the
# directory containing SFMLConfig.cmake. For example:
# set(SFML_DIR "<path-to-sfml>/lib/cmake/SFML")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(include)

configure_file(resources/background.png ${CMAKE_CURRENT_BINARY_DIR}/resources/background.png COPYONLY)
configure_file(resources/pacman.png ${CMAKE_CURRENT_BINARY_DIR}/resources/pacman.png COPYONLY)

add_executable(2D_game_assignment
        src/main.cpp
        src/game.cpp
        # Add other source files if necessary
)

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
