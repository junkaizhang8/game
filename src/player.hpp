#pragma once

class Player
{
public:
    Player(int xpos, int ypos, int zpos, double rotation);
    ~Player();

private:
    int x;    // Player x position
    int y;    // Player y position
    int z;    // Player z position
    double r; // Player angle of rotation on horizontal plane
};