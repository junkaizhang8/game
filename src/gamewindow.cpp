#include <iostream>
#include <GLFW/glfw3.h>
#include "gamewindow.hpp"
#include "keyevent.hpp"
#include "gamekeyevent.hpp"

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

    KeyEvent::setKeyEvent(&keys);
    glfwSetKeyCallback(window, keyCallback);

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
}