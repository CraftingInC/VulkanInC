/* Unknown license from original author. Once I rewrite it, it will be MIT. */

#ifndef LOGGING_H
#define LOGGING_H

// Code borrowed from this article : https://tuttlem.github.io/2012/12/08/simple-logging-in-c.html
// I have plans to rewrite this. I just needed something simple to get started.

#include <stdio.h>   // FILE
#include <stdarg.h>  // va_start    va_end

void _log(FILE *file, const char *fmt, ...);

#define log(f, ...) _log(f   , __VA_ARGS__)

#endif // LOGGING_H
