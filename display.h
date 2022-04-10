#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdbool.h>

bool createWindow(int w, int h, const char* windowTitle);
bool isWindowClosed(void);
void pollEvents(void);
void terminateWindow(void);

#endif // DISPLAY_H
