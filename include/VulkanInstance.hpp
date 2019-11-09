#pragma once

#include <vulkan/vulkan.hpp>

class VulkanInstance {

private:
    VkInstance instance;

private:
    VulkanInstance();

public:
    static VulkanInstance& getInstance();
    static VkInstance getNativeInstance();
    void destroy();

    VulkanInstance(VulkanInstance const&) = delete;
    void operator=(VulkanInstance const&) = delete;

    std::vector<const char *> getRequiredExtensions();
};