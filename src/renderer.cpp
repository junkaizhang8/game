#include "renderer.hpp"

void Renderer::init(double left, double right, double bottom, double top, int scale)
{
    pixelScale = scale;
    pixelScaleHalf = pixelScale / 2;

    glPointSize((float)pixelScale);
    glOrtho(left, right, bottom, top, -1.0, 1.0);
}

void Renderer::setColour(int red, int green, int blue)
{
    glColor3ub(red, green, blue);
}

void Renderer::setColour(float red, float green, float blue)
{
    glColor3f(red, green, blue);
}

void Renderer::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::drawPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x * pixelScale, y * pixelScale);
    glEnd();
}