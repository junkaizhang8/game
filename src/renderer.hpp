#pragma once

#include <GLFW/glfw3.h>

class Renderer
{
public:
    Renderer() = default;
    ~Renderer() = default;
    void init(double left, double right, double bottom, double top, int scale);
    void setColour(int red, int green, int blue);
    void setColour(float red, float green, float blue);
    void clearScreen();
    void drawPixel(int x, int y);
    // void drawPixel(float x, float y);
    // void drawLine(int x1, int y1, int x2, int y2);
    // void drawLine(float x1, float y1, float x2, float y2);
private:
    int pixelScale;
    int pixelScaleHalf;
};