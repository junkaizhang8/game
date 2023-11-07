#include <GLFW/glfw3.h>
#include "timer.hpp"

Timer::Timer(int fps)
{
    maxfps = fps;
}

void Timer::updateTimer()
{
    time = glfwGetTime();
}

bool Timer::updateFrame()
{
    if (time - prevTime >= 1 / (double)maxfps)
    {
        prevTime = time;
        return true;
    }

    return false;
}