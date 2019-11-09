#pragma once

#include <string>
#include "Surface.hpp"

struct GLFWwindow;

class Window {

private:
    int width;
    int height;
    std::string title;

    GLFWwindow* glfwWindow;
    Surface* surface;

public:
    Window(int width, int height, std::string title);
    ~Window();

    void initWindow();

    void waitForWindowSize();

    Surface* createSurface();

    void getWindowSize(int* width, int* height);
    bool shouldClose();

    void destroy();
};