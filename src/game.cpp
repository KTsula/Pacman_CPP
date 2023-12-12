/*
 * File: game.cpp
 * Date: November 21, 2023
 * Description: Game class to deal with initialization and controller of 2D my game application.
 */
#include "../include/game.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

const float Game::SCENE_WIDTH = 800.0f;
const float Game::SCENE_HEIGHT = 600.0f;
const float Game::PLAYER_START_X = 400.0f;
const float Game::PLAYER_START_Y = 300.0f;
const float Game::RADIUS = 40.0f;

Game::Game() {
    initWindow();
    initBackground();
    initPlayer();
}
/**
 * Window initializer.
 */
int Game::initWindow() {
    window.create(sf::VideoMode(SCENE_WIDTH, SCENE_HEIGHT), "My 2D game");
    window.setFramerateLimit(120);
    return 0;
}
/**
 * Background initializer.
 */
int Game::initBackground() {
    if (!backgroundTexture.loadFromFile("resources/background.png")) {
        return 1;
    }
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT));
    return 0;
}

/**
 * Player (e.g. PacMan) initializer
 * @return 0 if successfully initialized, 1 otherwise
 */
int Game::initPlayer() {
    player.setRadius(RADIUS);
    player.setOrigin(RADIUS, RADIUS);
    player.setPosition(PLAYER_START_X, PLAYER_START_Y);
    if (!playerTexture.loadFromFile("resources/pacman.png")) {
        return 1;
    }
    player.setTexture(&playerTexture);
    return 0;
}

/**
 * Dealing with events on window.
 */
void Game::processInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Up:
                        playerDirection = sf::Vector2f(0, -1);
                        break;
                    case sf::Keyboard::Down:
                        playerDirection = sf::Vector2f(0, 1);
                        break;
                    case sf::Keyboard::Left:
                        playerDirection = sf::Vector2f(-1, 0);
                        break;
                    case sf::Keyboard::Right:
                        playerDirection = sf::Vector2f(1, 0);
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void Game::spawnGhost() {
    // Randomly generate time intervals between ghost appearances (within a range)
    float randomInterval = static_cast<float>(rand() % 2000 + 1000);
    if (ghostTimer.getElapsedTime().asMilliseconds() > randomInterval) {
        ghostTimer.restart();
        // Randomly generate position for the ghost
        float ghostX = static_cast<float>(rand() % static_cast<int>(SCENE_WIDTH));
        float ghostY = static_cast<float>(rand() % static_cast<int>(SCENE_HEIGHT));

        // Create and set properties for the ghost sprite using a texture
        sf::CircleShape ghost;
        ghost.setRadius(RADIUS/2);
        ghost.setOrigin(RADIUS/2, RADIUS/2);
        ghost.setPosition(ghostX, ghostY);
        if (!ghostTexture.loadFromFile("resources/ghost.png")) {
            std::cout << "Error loading ghost texture" << std::endl;
        }

        ghost.setTexture(&ghostTexture);

        // Generate a random direction for the ghost
        sf::Vector2f randomDirection(rand() % 3 - 1, rand() % 3 - 1);
        sf::Vector2f ghostDirection = randomDirection;
        // Add the ghost and its direction to the respective vectors
        ghosts.push_back(ghost);
        ghostDirections.push_back(ghostDirection);
    }
}


/**
 * Function to update the position of the player and ghosts.
 */
void Game::update() {
    processInput();

    // Spawn a new ghost
    spawnGhost();

    // Ghost movement

    float ghost_speed = 2.0f; // Adjust ghost speed as needed

    // Update the position of each ghost based on its direction
    for (size_t i = 0; i < ghosts.size(); ++i) {
        // Get current ghost position
        sf::Vector2f ghostPosition = ghosts[i].getPosition();

        // Get the ghost's current direction
        sf::Vector2f currentDirection = ghostDirections[i];

        // Update the ghost's position based on the current direction and speed
        sf::Vector2f newGhostPosition = ghostPosition + ghost_speed * currentDirection;

        // Check window boundaries for the ghost and make it reflect on hitting the edges
        if (newGhostPosition.x < 0 || newGhostPosition.x > SCENE_WIDTH - ghosts[i].getGlobalBounds().width) {
            currentDirection.x = -currentDirection.x;
            ghostDirections[i] = currentDirection;
        }
        if (newGhostPosition.y < 0 || newGhostPosition.y > SCENE_HEIGHT - ghosts[i].getGlobalBounds().height) {
            currentDirection.y = -currentDirection.y;
            ghostDirections[i] = currentDirection;
        }

        // Update ghost position
        ghosts[i].setPosition(newGhostPosition);
    }

    // Player movement

    float player_speed = 5.0f; // Adjust speed as needed

    // Get the current position
    sf::Vector2f position = player.getPosition();

    // Calculate the new position
    sf::Vector2f newPosition = position + player_speed * playerDirection;

    // Check for horizontal boundaries
    if (newPosition.x - RADIUS < 0) {
        newPosition.x = RADIUS;
    } else if (newPosition.x + RADIUS > SCENE_WIDTH) {
        newPosition.x = SCENE_WIDTH - RADIUS;
    }

    // Check for vertical boundaries
    if (newPosition.y - RADIUS < 0) {
        newPosition.y = RADIUS;
    } else if (newPosition.y + RADIUS > SCENE_HEIGHT) {
        newPosition.y = SCENE_HEIGHT - RADIUS;
    }

    // Update the position
    player.setPosition(newPosition);

    // Collision detection between player and ghosts
    for (size_t i = 0; i < ghosts.size(); ++i) {
        if (player.getGlobalBounds().intersects(ghosts[i].getGlobalBounds())) {
            // Collision detected, remove the ghost
            ghosts.erase(ghosts.begin() + i);
            ghostDirections.erase(ghostDirections.begin() + i);
            // Perform any action we want upon collision (e.g., score update, game over)
            // ...
        }
    }
}



/**
 * Render elements in the window
 */
void Game::render() {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);

    // Draw all ghosts present on the screen
    for (const auto& ghost : ghosts) {
        window.draw(ghost);
    }

    window.display();
}
/**
 * Main function to deal with events, update the player and render the updated scene on the window.
 */
int Game::run() {
    srand(static_cast<unsigned>(time(nullptr)));
    while (window.isOpen()) {
        update();
        render();
    }
    return 0;
}