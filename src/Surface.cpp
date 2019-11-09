#include "Surface.hpp"
#include "VulkanInstance.hpp"

Surface::Surface(VkSurfaceKHR VkSurface) : surface(VkSurface)
{
}

Surface::~Surface()
{
}

VkSurfaceKHR Surface::get()
{
    return surface;
}

void Surface::destroy()
{
    vkDestroySurfaceKHR(VulkanInstance::getNativeInstance(), surface, nullptr);
}