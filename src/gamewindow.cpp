#include <iostream>
#include <GLFW/glfw3.h>
#include "gamewindow.hpp"
#include "keyevent.hpp"

bool GameWindow::initiated = false;
GLFWwindow *GameWindow::windowAddr = nullptr;
KeyEvent GameWindow::keys;

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    GameWindow::keyEventCheck(window, key, scancode, action, mods);
}

GameWindow::~GameWindow()
{
    if (window)
    {
        close();
    }
    std::cout << "Game window destroyed successfully." << std::endl;
}

int GameWindow::init(int width, int height, const char *title)
{
    if (initiated)
    {
        return RET_ERROR;
    }
    if (!glfwInit())
    {
        return RET_ERROR;
    }
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        close();
        return RET_ERROR;
    }
    glfwSetWindowUserPointer(window, this);
    glfwSetKeyCallback(window, keyCallback);

    initiated = true;
    windowAddr = window;

    return RET_SUCCESS;
}

void GameWindow::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwPollEvents();

    glColor3ub(255, 0, 0);

    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();

    glfwSwapBuffers(window);
}

bool GameWindow::isRunning()
{
    return !glfwWindowShouldClose(window);
}

void GameWindow::close()
{
    glfwTerminate();

    initiated = false;
    windowAddr = nullptr;
    keys.resetKeys();
}

void GameWindow::keyEventCheck(GLFWwindow *theWindow, int key, int scancode, int action, int mods)
{
    if (theWindow != windowAddr)
    {
        return;
    }
    keyDown(key, action);
    keyUp(key, action);
}

void GameWindow::keyDown(int key, int action)
{
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        keys.setWPressed(true);
    }
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        keys.setSPressed(true);
    }
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        keys.setAPressed(true);
    }
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        keys.setDPressed(true);
    }
}

void GameWindow::keyUp(int key, int action)
{
    if (key == GLFW_KEY_W && action == GLFW_RELEASE)
    {
        keys.setWPressed(false);
    }
    if (key == GLFW_KEY_S && action == GLFW_RELEASE)
    {
        keys.setSPressed(false);
    }
    if (key == GLFW_KEY_A && action == GLFW_RELEASE)
    {
        keys.setAPressed(false);
    }
    if (key == GLFW_KEY_D && action == GLFW_RELEASE)
    {
        keys.setDPressed(false);
    }
}