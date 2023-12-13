/*
 * File: game.h
 * Date: November 21, 2023
 * Description: Game class header.
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class GameTest; // forward declaration (i looked this up so i can test my things later)

class Game {
public:
    Game();

    // i tried to use friend classes but it didnt work so i just made what im testing public
    static const float PLAYER_START_X;
    static const float PLAYER_START_Y;
    sf::Clock ghostTimer;
    std::vector<sf::CircleShape> ghosts;
    sf::Vector2f getPlayerPosition() const { return player.getPosition(); }
    const std::vector<sf::CircleShape>& getGhosts() const { return ghosts; }

    int initWindow();
    int initBackground();
    int initPlayer();
    int run();
    bool isWindowOpen() const { return window.isOpen(); }
    void spawnGhost();


private:
    friend class GameTest; // this way we can test all of the private things when we test!
    static const float SCENE_WIDTH;
    static const float SCENE_HEIGHT;
    static const float RADIUS;
    sf::RenderWindow window;
    sf::Texture backgroundTexture;
    sf::Sprite background;
    sf::Texture playerTexture;
    sf::CircleShape player;
    sf::Vector2f playerDirection;
    // Vector to store ghost sprites
    sf::Texture ghostTexture; // Ghost texture
    std::vector<sf::Vector2f> ghostDirections; // Vector to store ghost movement directions
    std::string playerName;
    int ghostsEaten;
    bool roundEnded;
    sf::Clock roundTimer;
    sf::Text scoreboardText;
    sf::Font font;

    void processInput();
    void update();
    void render();
    void inputPlayerName();
    void checkRoundEnd();
    void displayScoreboard();
};