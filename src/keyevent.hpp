#pragma once

#include <GLFW/glfw3.h>

class KeyEvent
{
public:
    KeyEvent() = default;
    virtual ~KeyEvent() = default;
    virtual void resetKeys() = 0;
    static void checkKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods);
    static void setKeyEvent(KeyEvent *newKeyEvent);

protected:
    static KeyEvent *keyEvent;
    virtual void handleKeyEvent(int key, int action) = 0;
};