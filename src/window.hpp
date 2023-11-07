#pragma once

#include <GLFW/glfw3.h>
#include "renderer.hpp"
#include "timer.hpp"

#define INIT_SUCCESS 0
#define INIT_ERROR -1
#define DEFAULT_WINDOW_WIDTH 120
#define DEFAULT_WINDOW_HEIGHT 80
#define DEFAULT_PIXEL_SCALE 8

class Window
{
public:
    Window();
    virtual ~Window() = default;
    virtual int init(int width, int height, int pixelScale, const char *title) = 0;
    virtual void display() = 0;
    virtual bool isRunning() = 0;
    virtual void close() = 0;

protected:
    GLFWwindow *window;
    Renderer renderer;
    Timer timer;
};