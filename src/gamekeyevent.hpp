#pragma once

#include "keyevent.hpp"

class GameKeyEvent : public KeyEvent
{
public:
    GameKeyEvent() = default;
    ~GameKeyEvent() = default;
    void resetKeys() override;
    bool getW() {return w;}
private:
    bool w = false;
    bool s = false;
    bool a = false;
    bool d = false;
    void handleKeyEvent(int key, int action) override;
};