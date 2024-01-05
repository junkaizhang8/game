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

    windowWidth = width;
    windowHeight = height;

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

    renderer = std::make_shared<Renderer>();

    renderer->init(0.0, (double)scaledWidth, (double)scaledHeight, 0.0, pixelScale);

    KeyEvent::setKeyEvent(&keys);
    KeyEvent::setKeyCallback(window);

    return INIT_SUCCESS;
}

void Game::run()
{
    display();
}

void Game::update() {}

void Game::display()
{   
    if (clock.updateFrame())
    {
        renderer->setColour(255, 0, 0);
        player.updatePosition(keys);
        renderer->clearScreen();
        renderer->drawPixel(player.getX(), player.getY());
        renderer->setColour(0, 255, 0);
        renderer->drawHollowCircle(100, 30, 1);
        glfwSwapBuffers(window);
    }
    glfwPollEvents();
    clock.updateClock();
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