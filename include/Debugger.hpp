#pragma once

#include <vulkan/vulkan.hpp>

const std::vector<const char*> validationLayers = {
    "VK_LAYER_KHRONOS_validation"
};

class Debugger {

public:
    static Debugger& getInstance();

    Debugger(Debugger const&) = delete;
    void operator=(Debugger const&) = delete;

private:
    Debugger();


private:
    VkDebugUtilsMessengerEXT debugMessenger;

    bool checkValidationLayerSupport();

public:
    void debugExtensions();
    void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT &createInfo);
    void setupDebugMessenger();
    void destroy();
};