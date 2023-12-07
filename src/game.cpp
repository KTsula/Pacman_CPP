/*
 * File: game.cpp
 * Author: Miranda Drummond
 * Date: November 21, 2023
 * Description: Game class to deal with initialization and controller of 2D my game application.
 */
#include "game.h"

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



/**
 * Function to update the position of the player
 */
void Game::update() {
    float speed = 5.0f; // Adjust speed as needed

    // Get the current position
    sf::Vector2f position = player.getPosition();

    // Calculate the new position
    sf::Vector2f newPosition = position + speed * playerDirection;

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
}



/**
 * Render elements in the window
 */
void Game::render() {
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    window.display();
}
/**
 * Main function to deal with events, update the player and render the updated scene on the window.
 */
int Game::run() {
    while (window.isOpen()) {
        processInput();
        update();
        render();
    }
    return 0;
}