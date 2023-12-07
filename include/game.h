/*
 * File: game.h
 * Date: November 21, 2023
 * Description: Game class header.
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Game {
public:
    Game();
    int run();

private:
    static const float SCENE_WIDTH;
    static const float SCENE_HEIGHT;
    static const float PLAYER_START_X;
    static const float PLAYER_START_Y;
    static const float RADIUS;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture playerTexture;
    sf::CircleShape player;
    sf::Vector2f playerDirection;
    std::vector<sf::CircleShape> ghosts; // Vector to store ghost sprites
    sf::Texture ghostTexture; // Ghost texture
    std::vector<sf::Vector2f> ghostDirections; // Vector to store ghost movement directions
    sf::Clock ghostTimer; // Timer for ghost appearance

    int initWindow();
    int initBackground();
    int initPlayer();
    void processInput();
    void update();
    void render();
    void spawnGhost();
};