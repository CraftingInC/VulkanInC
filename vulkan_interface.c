#include "vulkan_interface.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdio.h>   // printf()
#include <stdlib.h>  // malloc()  free()
#include <string.h>  // memcpy()

#include "logging.h"

VkInstance m_instance;     // This is temporary. Eventually will be part of a local struct.

bool vulkanInit(FILE *fp)
{
    log(fp, "----- VULKAN INFO -----");

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

    log(fp, "%d extensions supported", extensionCount);

    uint32_t pApiVersion = VK_API_VERSION_1_0;
    VkResult result = vkEnumerateInstanceVersion(&pApiVersion);
    if(result != VK_SUCCESS)
    {
       pApiVersion = VK_API_VERSION_1_0;
    }

    uint32_t major   = VK_API_VERSION_MAJOR(pApiVersion);
    uint32_t minor   = VK_API_VERSION_MINOR(pApiVersion);
    uint32_t patch   = VK_API_VERSION_PATCH(pApiVersion);

    log(fp, "VULKAN VERSION : %d.%d.%d", major, minor, patch);

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pNext = NULL;
    appInfo.pApplicationName = "VulkanInC";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = pApiVersion;

    uint32_t requiredInstanceExtensionCount;
    const char **requiredInstanceExtensions = glfwGetRequiredInstanceExtensions(&requiredInstanceExtensionCount);
    uint32_t extension_count = requiredInstanceExtensionCount;

    log(fp, "Total GLFW3 required extension count : %d", extension_count);

    const char** extensions = malloc(sizeof(char*) * extension_count);
    memcpy(extensions, requiredInstanceExtensions, sizeof(char*) * requiredInstanceExtensionCount);

    log(fp, " ");

    for(uint32_t t = 0; t < extension_count; t++)
    {
        log(fp, "%d.) GLFW3 Extension Name : %s", t + 1, extensions[t]);
    }

    log(fp, " ");

    VkInstanceCreateInfo instance_create_info = {};
    instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.flags = 0;
    instance_create_info.pApplicationInfo = &appInfo;
    instance_create_info.enabledLayerCount = 0;
    instance_create_info.enabledExtensionCount = extension_count;
    instance_create_info.ppEnabledExtensionNames = extensions;

    VkResult err = vkCreateInstance(&instance_create_info, NULL, &m_instance);
    if(err != VK_SUCCESS)
    {
        log(fp, "Unable to create a vkCreateInstance.");
        return false;
    } else {
        uint32_t physicalDeviceCount = 0;
        vkEnumeratePhysicalDevices(m_instance, &physicalDeviceCount, NULL);
        log(fp, "Total Devices : %d", physicalDeviceCount);
        log(fp, "Application Name : %s", instance_create_info.pApplicationInfo->pApplicationName);
    }

    free(extensions);
    return true;
}

void vulkanShutdown()
{
    if(m_instance != NULL)
    {
        vkDestroyInstance(m_instance, NULL);
        m_instance = NULL;
    }
}

