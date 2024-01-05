#include <GLFW/glfw3.h>
#include "clock.hpp"

Clock::Clock(int fps)
{
    dt = 1 / (double)fps;
}

void Clock::updateClock()
{
    time = glfwGetTime();
}

bool Clock::updateFrame()
{
    if (time - prevTime >= dt)
    {
        prevTime = time;
        return true;
    }

    return false;
}