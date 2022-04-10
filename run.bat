gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -c display.c -o display.o
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -c vulkan_interface.c -o vulkan_interface.o
gcc.exe -Wall -std=c17 -m64 -O2 -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -c main.c -o main.o
gcc.exe -LC:\VulkanSDK\1.3.204.1\Lib -o VulkanInC.exe main.o display.o vulkan_interface.o -static -m64 -s -lglfw3 -lvulkan-1 -lgdi32

del *.o
