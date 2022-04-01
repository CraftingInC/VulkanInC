#include "display.h"

GLFWwindow* window = NULL;

bool createWindow()
{
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(800, 600, "Vulkan Window in C", NULL, NULL);
	return true;
}

bool isWindowClosed()
{
	return glfwWindowShouldClose(window);
}

void terminateWindow()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}