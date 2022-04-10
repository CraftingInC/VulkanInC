/*
This code is a skeleton example to make sure cglm and vulkan are working.

Works with c99, c11 and c17

My run.bat file has this :
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -c display.c -o display.o
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -c vulkan_interface.c -o vulkan_interface.o
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -c main.c -o main.o
gcc.exe -LC:\VulkanSDK\1.3.204.1\Lib -o VulkanInC.exe main.o display.o vulkan_interface.o -static -m64 -s -lglfw3 -lvulkan-1 -lgdi32

I could have used a makefile, but I'm lazy.

NOTICE ---> 1.3.204.1 is the vulkan version number I use.
            Your version might be different.
            Update your version number as needed.

-mwindows -- to get rid of the console under windows when compiling release mode.
*/

#include "display.h"
#include "vulkan_interface.h"

#include <cglm/cglm.h>
#include <stdio.h>

int main()
{
	if(createWindow(800, 600, "Vulkan Window in C"))
	{
        if(vulkanInit() == false)
        {
            terminateWindow();
        }

        printf("\n----- CGLM MATH TEST -----\n");
        vec3 v1 = {0.4f, 0.2f, 0.0f};
        glm_vec3_rotate(v1, glm_rad(45), (vec3){0.7f, 0.6f, 0.3f});

        printf("%f, %f, %f\n", v1[0], v1[1], v1[2]);

        while(!isWindowClosed())
        {
            pollEvents();
        }

        vulkanShutdown();
        terminateWindow();
	}
    return 0;
}
