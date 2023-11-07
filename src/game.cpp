#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <GLFW/glfw3.h>
#include "keyevent.hpp"
#include "gamekeyevent.hpp"
#include "game.hpp"

Game::~Game()
{
    if (window)
    {
        close();
    }
    std::cout << "Game window destroyed successfully." << std::endl;
}

int Game::init(int width, int height, int pixelScale, const char *title)
{
    if (!glfwInit())
    {
        return INIT_ERROR;
    }

    int scaledWidth = width * pixelScale;
    int scaledHeight = height * pixelScale;

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(scaledWidth, scaledHeight, title, NULL, NULL);
    if (!window)
    {
        close();
        return INIT_ERROR;
    }
    
    glfwMakeContextCurrent(window);

    glfwSetWindowUserPointer(window, this);

    glfwSwapInterval(1);

    renderer.init(0.0, (double)scaledWidth, (double)scaledHeight, 0.0, pixelScale);
    renderer.setColour(255, 0, 0);

    KeyEvent::setKeyEvent(&keys);
    KeyEvent::setKeyCallback(window);

    return INIT_SUCCESS;
}

void Game::display()
{   
    if (timer.updateFrame())
    {
        player.updatePosition(keys);
        renderer.clearScreen();
        renderer.drawPixel(player.getX(), player.getY());
        glfwSwapBuffers(window);
    }
    glfwPollEvents();
    timer.updateTimer();
}

bool Game::isRunning()
{
    return !glfwWindowShouldClose(window);
}

void Game::close()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}