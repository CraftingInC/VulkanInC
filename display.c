#include "display.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

GLFWwindow* window = NULL;    // This will be part of a local struct.

bool createWindow(int w, int h, const char* windowTitle)
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(w, h, windowTitle, NULL, NULL);
	return true;
}

bool isWindowClosed()
{
	return glfwWindowShouldClose(window);
}

void pollEvents()
{
    glfwPollEvents();
}

void terminateWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}
