#pragma once

#include <GLFW/glfw3.h>

#define RET_SUCCESS 0
#define RET_ERROR -1
#define DEFAULT_WINDOW_WIDTH 1024
#define DEFAULT_WINDOW_HEIGHT 512

class Window
{
public:
    Window();
    virtual ~Window() = default;
    virtual int init(int width, int height, const char *title) = 0;
    virtual void display() = 0;
    virtual bool isRunning() = 0;
    virtual void close() = 0;

protected:
    GLFWwindow *window;
};