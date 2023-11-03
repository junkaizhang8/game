#include <GLFW/glfw3.h>
#include "keyevent.hpp"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    KeyEvent::checkKeyEvent(window, key, scancode, action, mods);
}

KeyEvent *KeyEvent::keyEvent = nullptr;

void KeyEvent::checkKeyEvent(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (keyEvent == nullptr)
    {
        return;
    }
    keyEvent->handleKeyEvent(key, action);
}

void KeyEvent::setKeyEvent(KeyEvent *newKeyEvent)
{
    keyEvent = newKeyEvent;
}