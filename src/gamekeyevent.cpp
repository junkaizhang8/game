#include <GLFW/glfw3.h>
#include "keyevent.hpp"
#include "gamekeyevent.hpp"
#include <iostream>

void GameKeyEvent::resetKeys()
{
    w = false;
    s = false;
    a = false;
    d = false;
    left = false;
    right = false;
}

void GameKeyEvent::handleKeyEvent(GLFWwindow *window, int key, int action)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case (GLFW_KEY_W):
            w = true;
            break;
        case (GLFW_KEY_S):
            s = true;
            break;
        case (GLFW_KEY_A):
            a = true;
            break;
        case (GLFW_KEY_D):
            d = true;
            break;
        case (GLFW_KEY_LEFT):
            left = true;
            break;
        case (GLFW_KEY_RIGHT):
            right = true;
            break;
        default:
            break;
        }
    }
    else if (action == GLFW_RELEASE)
    {
        switch (key)
        {
        case (GLFW_KEY_W):
            w = false;
            break;
        case (GLFW_KEY_S):
            s = false;
            break;
        case (GLFW_KEY_A):
            a = false;
            break;
        case (GLFW_KEY_D):
            d = false;
            break;
        case (GLFW_KEY_LEFT):
            left = false;
            break;
        case (GLFW_KEY_RIGHT):
            right = false;
            break;
        default:
            break;
        }
    }
}