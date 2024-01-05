#pragma once

#define DEFAULT_FPS 30

class Clock
{
public:
    Clock() = default;
    Clock(int fps);
    ~Clock() = default;
    void updateClock();
    bool updateFrame();

private:
    double time = 0;
    double prevTime = 0;
    double dt = 1 / (double)DEFAULT_FPS;
};