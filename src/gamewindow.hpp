#pragma once

#include <GLFW/glfw3.h>
#include "window.hpp"
#include "gamewindow.hpp"
#include "keyevent.hpp"
#include "gamekeyevent.hpp"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);

class GameWindow : public Window
{
public:
    GameWindow() = default;
    ~GameWindow();
    int init(int width, int height, const char *title) override;
    void display() override;
    bool isRunning() override;
    void close() override;

private:
    GameKeyEvent keys;      // Store key press statuses of movement keys
};