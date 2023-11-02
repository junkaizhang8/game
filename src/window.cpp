#include <iostream>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>
#include "window.hpp"

Window::Window() : window(nullptr) {}

Window::~Window()
{
    if (window)
    {
        close();
    }
    std::cout << "Game window destroyed successfully." << std::endl;
}

int Window::init(int width, int height, const char *title)
{
    if (!glfwInit())
    {
        return RET_ERROR;
    }
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        close();
        return RET_ERROR;
    }
    glfwMakeContextCurrent(window);

    return RET_SUCCESS;
}

void Window::display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Window::isRunning()
{
    return !glfwWindowShouldClose(window);
}

void Window::close() {
    glfwTerminate();
}