#include "player.hpp"

Player::Player(int xpos, int ypos, int zpos, double rotation) : x(xpos), y(ypos), z(zpos), r(rotation) {}

void Player::setPlayerPosition(int newX, int newY, int newZ, double newR)
{
    x = newX;
    y = newY;
    z = newZ;
    r = newR;
}

void Player::updatePosition(GameKeyEvent &keys)
{
    if (keys.wPressed())
    {
        y--;
    }
    if (keys.sPressed())
    {
        y++;
    }
    if (keys.aPressed())
    {
        x--;
    }
    if (keys.dPressed())
    {
        x++;
    }
}