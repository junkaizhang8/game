#include <iostream>
#include <GLFW/glfw3.h>
#include "window.hpp"
#include "game.hpp"
#include "player.hpp"

int main(int argc, char *argv[])
{
    Game game;
    game.init(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, DEFAULT_PIXEL_SCALE, "Game Window");

    while (game.isRunning())
    {
        game.display();
    }

    game.close();
    
    return EXIT_SUCCESS;
}