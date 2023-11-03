#pragma once

#include <GLFW/glfw3.h>
#include "window.hpp"
#include "keyevent.hpp"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

class GameWindow : public Window
{
public:
    ~GameWindow() override;
    int init(int width, int height, const char *title) override;
    void display() override;
    bool isRunning() override;
    void close() override;
    static void keyEventCheck(GLFWwindow *theWindow, int key, int scancode, int action, int mods);

private:
    static KeyEvent keys;                       // Store key press statuses of movement keys
    static void keyDown(int flag, int action);
    static void keyUp(int flag, int action);
    static bool initiated;
    static GLFWwindow *windowAddr;              // Static address to prevent illegal access through
                                                // keyCallback to modify keys with other windows
};