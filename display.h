#ifndef DISPLAY_H
#define DISPLAY_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdbool.h>
#include <stddef.h>

bool createWindow();
bool isWindowClosed();
void terminateWindow();

#endif // DISPLAY_H