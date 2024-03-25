#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "player.h"
using namespace std;

Player::Player(const std::string& playerName) : name(playerName) {}

std::string Player::getName() const {
    return name;
}