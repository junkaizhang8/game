#include "cursor.hpp"

void Cursor::setPixelScale(int scale)
{
    pixelScale = scale;
}

// Get cursor position in standard coordinate scale
void Cursor::getCursorPos(GLFWwindow *window, double *x, double *y)
{
    glfwGetCursorPos(window, x, y);
}

// Get cursor position in terms of the pixel scale
// (e.g. (100, 200) in terms of the standard coordinate scale
// becomes (10, 20) using a pixel scale of 10)
void Cursor::getScaledCursorPos(GLFWwindow *window, double *x, double *y)
{
    double standardX;
    double standardY;
    glfwGetCursorPos(window, &standardX, &standardY);
    *x = (int)(standardX / pixelScale);
    *y = (int)(standardY / pixelScale);
}