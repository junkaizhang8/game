#include <iostream>
#include <GLFW/glfw3.h>
#include "player.hpp"

Player::Player(int xpos, int ypos, int zpos, double rotation) : x(xpos), y(ypos), z(zpos), r(rotation) {}

Player::~Player() {}