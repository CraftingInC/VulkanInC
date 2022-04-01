gcc.exe -Wall -std=c17 -m64 -fomit-frame-pointer -fexpensive-optimizations -Os -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -Ilibs\stb-master -c display.c -o display.o
gcc.exe -Wall -std=c17 -m64 -fomit-frame-pointer -fexpensive-optimizations -Os -IC:\VulkanSDK\1.3.204.1\Include -Ilibs\glfw-master\include -Ilibs\glfw-master\src -Ilibs\cglm-master\include -Ilibs\stb-master -c main.c -o main.o
gcc.exe -LC:\VulkanSDK\1.3.204.1\Lib -o VulkanInC.exe main.o display.o -static -m64 -lglfw3 -lvulkan-1 -lgdi32 -s

del *.o
