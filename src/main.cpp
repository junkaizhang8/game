#include <iostream>
#include <GLFW/glfw3.h>
#include "window.hpp"

int main(int argc, char *argv[])
{
    Window game;
    game.init(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, "Game Window");
    while (game.isRunning())
    {
        game.display();
    }
    game.close();
    return EXIT_SUCCESS;
}