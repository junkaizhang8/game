#pragma once

#include <GLFW/glfw3.h>
#include <iostream>

class KeyEvent
{
public:
    KeyEvent() = default;
    ~KeyEvent() = default;
    void resetKeys() {w = false; s = false; a = false; d = false;}
    bool wPressed() {return w;}
    void setWPressed(bool status) {w = status;}
    bool sPressed() {return s;}
    void setSPressed(bool status) {s = status;}
    bool aPressed() {return a;}
    void setAPressed(bool status) {a = status;}
    bool dPressed() {return d;}
    void setDPressed(bool status) {d = status;}

private:
    bool w = false;
    bool s = false;
    bool a = false;
    bool d = false;
};