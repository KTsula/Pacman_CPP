// Created by Miranda Drummond on 11/12/2023.
//
#include "gtest/gtest.h"
#include "../include/game.h"
#include <thread>

// Test Fixture for Game class tests
class GameTest : public ::testing::Test {
protected:
    Game game;

    void SetUp() override {
        game.initWindow();
        game.initBackground();
        game.initPlayer();
        // Any other initialization needed
    }
};

// Test for game window initialization
TEST_F(GameTest, InitWindow) {
    EXPECT_EQ(0, game.initWindow());
}

// Test for background initialization
TEST_F(GameTest, InitBackground) {
    EXPECT_EQ(0, game.initBackground());
}

// Test for player initialization
TEST_F(GameTest, InitPlayer) {
    EXPECT_EQ(0, game.initPlayer());
}

// Test for running the game
TEST_F(GameTest, RunGame) {
    EXPECT_EQ(0, game.run());
}

TEST_F(GameTest, WindowIsOpenAfterInit) {
    game.initWindow();
    EXPECT_TRUE(game.isWindowOpen());
}

// Test to check if the player position is set correctly after initialization
TEST_F(GameTest, PlayerPositionAfterInit) {
    game.initPlayer();
    auto position = game.getPlayerPosition();
    EXPECT_EQ(position.x, Game::PLAYER_START_X);
    EXPECT_EQ(position.y, Game::PLAYER_START_Y);
}

// Test to check if ghosts are spawned correctly
TEST_F(GameTest, GhostCreation) {
    // Force the timer to simulate elapsed time
    game.ghostTimer.restart();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // simulate time delay

    game.spawnGhost();

    // Check if a ghost is added
    EXPECT_FALSE(game.ghosts.empty());

    // Additional checks can be done for the properties of the ghost
}