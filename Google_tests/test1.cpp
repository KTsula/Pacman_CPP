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

    void TearDown() override {
        // Close the game window and reset any necessary state
        game.window.close();
        // Add any additional cleanup or state reset code here
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

// check scoreboard is rendering correctly
TEST_F(GameTest, ScoreboardRender) {
    game.initWindow();
    game.initBackground();
    game.initPlayer();
    game.displayScoreboard();
    EXPECT_EQ(0, game.run());
}