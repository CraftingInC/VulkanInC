/*
This code is a skeleton example to make sure cglm and vulkan are working.

Works with c11 and c17

My run.bat file has this :
gcc.exe -Wall -std=c17 -m64 -fomit-frame-pointer -fexpensive-optimizations -Os -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -Ilibs\stb-master -c display.c -o display.o
gcc.exe -Wall -std=c17 -m64 -fomit-frame-pointer -fexpensive-optimizations -Os -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -Ilibs\stb-master -c main.c -o main.o
gcc.exe -LC:\VulkanSDK\1.3.204.1\Lib -o VulkanInC.exe main.o display.o -static -m64 -lglfw3 -lvulkan-1 -lgdi32 -s

NOTICE ---> 1.3.204.1 is the vulkan version number I use.
            Your version might be different.
            Update your version number as needed.

-mwindows -- to get rid of the console under windows when compiling release mode.

NOTE : STATIC is IMPORTANT to get rid of cookie issues !!!

This vulkan demo is too simple for me to bother using / creating a makefile.
*/

#include "display.h"
#include <cglm/cglm.h>
#include <stdio.h>

int main()
{
	if(createWindow())
	{
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

		vec3 v1 = {0.4f, 0.2f, 0.0f};
		glm_vec3_rotate(v1, glm_rad(45), (vec3){0.7f, 0.6f, 0.3f});

		printf("%f, %f, %f\n", v1[0], v1[1], v1[2]);

		while(!isWindowClosed())
		{
			glfwPollEvents();
		}

        terminateWindow();
	}
    return 0;
}
