//
// Created by Miranda Drummond on 11/12/2023.
//
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "../include/game.h"

// Test Fixture for Game class tests
class GameTest:public::testing::Test {
protected:
    Game game; // Game object used in all tests

    void SetUp() override {
        // Setup code executed before each test, if needed
    }

    void TearDown() override {
        // Teardown code executed after each test, if needed
    }
};

TEST(GameTest, run) {
    Game game;
    EXPECT_EQ(0, game.run());
}

TEST(GameTest, initWindow) {
    Game game;
    EXPECT_EQ(0, game.initWindow());
}