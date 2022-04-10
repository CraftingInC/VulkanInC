/*
MIT License at the bottom of this file.

This code is a skeleton example to make sure cglm and vulkan are working.

Works with c99, c11 and c17

My run.bat file has this :
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\cglm-master\include -c display.c -o display.o
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\cglm-master\include -c logging.c -o logging.o
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\cglm-master\include -c vulkan_interface.c -o vulkan_interface.o
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\cglm-master\include -c main.c -o main.o
gcc.exe -LC:\VulkanSDK\1.3.204.1\Lib -o VulkanInC.exe main.o display.o logging.o vulkan_interface.o -static -m64 -s -lglfw3 -lvulkan-1 -lgdi32

-lgdi32   -- Windows only. Everything else is cross-platform.
-mwindows -- Windows only. Add this to the last line to get rid of the console interface.

I could have used a makefile, but I'm lazy.

NOTICE ---> 1.3.204.1 is the vulkan version number I use.
            Your version might be different.
            Update your version number as needed.


*/

#include "display.h"
#include "vulkan_interface.h"

#include <cglm/cglm.h>
#include <stdio.h>

#include "logging.h"

int main()
{
	if(createWindow(800, 600, "Vulkan Window in C"))
	{
        FILE *fp;
        fp = fopen("log.txt", "w+");
        if(vulkanInit(fp) == false)
        {
            fclose(fp);
            terminateWindow();
        }

        log(fp, " ");
        log(fp, "----- CGLM MATH TEST -----");
        vec3 v1 = {0.4f, 0.2f, 0.0f};
        glm_vec3_rotate(v1, glm_rad(45), (vec3){0.7f, 0.6f, 0.3f});

        log(fp, "%f, %f, %f\n", v1[0], v1[1], v1[2]);
        log(fp, "----- END TEST -----");

        fclose(fp);
        while(!isWindowClosed())
        {
            pollEvents();
        }

        vulkanShutdown();
        terminateWindow();
	}
    return 0;
}

/*
MIT License

Copyright (c) 2022 CraftingInC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
