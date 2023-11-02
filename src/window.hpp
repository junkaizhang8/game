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
    ~Window();
    int init(int width, int , const char *title);
    void display();
    bool isRunning();
    void close();
private:
    GLFWwindow *window;
};