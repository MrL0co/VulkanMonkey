#include "Window.hpp"
#include "VulkanInstance.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

Window::Window(int width, int height, std::string title) : width(width), height(height)
{
}

Window::~Window()
{
}

void Window::initWindow()
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    //glfwSetWindowUserPointer(glfwWindow, this);
    //glfwSetFramebufferSizeCallback(window, framebufferResizeCallback);
}

void Window::waitForWindowSize()
{
    int width = 0, height = 0;
    while (width == 0 || height == 0)
    {
        glfwGetFramebufferSize(glfwWindow, &width, &height);
        glfwWaitEvents();
    }
}

Surface *Window::createSurface()
{
    VkSurfaceKHR VkSurface;

    if (glfwCreateWindowSurface(VulkanInstance::getNativeInstance(), glfwWindow, nullptr, &VkSurface) != VK_SUCCESS)
    {
        throw std::runtime_error("failed to create window surface!");
    }

    surface = new Surface(VkSurface);

    return surface;
}

void Window::getWindowSize(int *width, int *height)
{
    glfwGetFramebufferSize(glfwWindow, width, height);
}

bool Window::shouldClose()
{
    glfwWindowShouldClose(glfwWindow);
}

void Window::destroy()
{
    glfwDestroyWindow(glfwWindow);
}
