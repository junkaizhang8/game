#pragma once

#define DEFAULT_FPS 30

class Timer
{
public:
    Timer() = default;
    Timer(int fps);
    ~Timer() = default;
    void updateTimer();
    bool updateFrame();

private:
    double time = 0;
    double prevTime = 0;
    int maxfps = DEFAULT_FPS;
};