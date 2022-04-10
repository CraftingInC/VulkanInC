#include "vulkan_interface.h"

#include <vulkan/vulkan.h>
#include <stdio.h>

VkInstance m_instance;

bool vulkanInit()
{
    printf("----- VULKAN INFO -----\n");
    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(NULL, &extensionCount, NULL);

    printf("%d extensions supported\n", extensionCount);

    uint32_t pApiVersion = VK_API_VERSION_1_0;
    VkResult result = vkEnumerateInstanceVersion(&pApiVersion);
    if(result != VK_SUCCESS)
    {
       pApiVersion = VK_API_VERSION_1_0;
    }

    uint32_t major   = VK_API_VERSION_MAJOR(pApiVersion);
    uint32_t minor   = VK_API_VERSION_MINOR(pApiVersion);
    uint32_t patch   = VK_API_VERSION_PATCH(pApiVersion);

    printf("VULKAN VERSION : %d.%d.%d\n", major, minor, patch);

    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "VulkanInC";
    appInfo.applicationVersion = 1;
    appInfo.apiVersion = pApiVersion;

    VkInstanceCreateInfo instance_create_info = {};
    instance_create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    instance_create_info.pApplicationInfo = &appInfo;


    VkResult err = vkCreateInstance(&instance_create_info, NULL, &m_instance);
    if(err != VK_SUCCESS)
    {
        printf("Unable to create a vkCreateInstance.\n");
        return false;
    } else {
        uint32_t physicalDeviceCount = 0;
        vkEnumeratePhysicalDevices(m_instance, &physicalDeviceCount, NULL);
        printf("Total Devices : %d\n", physicalDeviceCount);
        printf("Application Name : %s\n", instance_create_info.pApplicationInfo->pApplicationName);
    }

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

