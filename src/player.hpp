#pragma once

#include "gamekeyevent.hpp"

#define DEFAULT_PLAYER_X 10
#define DEFAULT_PLAYER_Y 10
#define DEFAULT_PLAYER_Z 10
#define DEFAULT_PLAYER_R 0.0

class Player
{
public:
    Player() = default;
    Player(int xpos, int ypos, int zpos, double rotation);
    ~Player() = default;
    void setPlayerPosition(int newX, int newY, int newZ, double newR);
    void updatePosition(GameKeyEvent &keys);
    int getX() { return x; }
    void setX(int newX) { x = newX; }
    int getY() { return y; }
    void setY(int newY) { y = newY; }

private:
    int x = DEFAULT_PLAYER_X;    // Player x position
    int y = DEFAULT_PLAYER_Y;    // Player y position
    int z = DEFAULT_PLAYER_Z;    // Player z position
    double r = DEFAULT_PLAYER_R; // Player angle of rotation on horizontal plane
};