#pragma once

#include <vulkan/vulkan.hpp>

class Surface {

private:
    VkSurfaceKHR surface;

public:
    Surface(VkSurfaceKHR VkSurface);
    ~Surface();

    VkSurfaceKHR get();
    void destroy();
};