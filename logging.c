/* MIT License at the bottom of this file. */

#include "logging.h"

#include <stdarg.h>  // va_start    va_end
#include <stdio.h>   // FILE
#include <time.h>    // time()  localtime()  strftime()  tzset()

FILE *fp;

void initLog()
{
    time_t t;
    char fileName[20];
    t = time(NULL);
    tzset();
    strftime(fileName, sizeof(fileName) - 1, "log-%m-%d-%Y.txt", localtime(&t));
    fp = fopen(fileName, "w+");
}

void _log(const char *fmt, ...)
{
    time_t t;
    char datestr[31];
    t = time(NULL);
    tzset();
    strftime(datestr, sizeof(datestr) - 1, "%H:%M:%S", localtime(&t));
    fprintf(fp, "%s : ", datestr);
    va_list ap;
    fp = (fp == NULL) ? stderr : fp;
    va_start(ap, fmt);
    vfprintf(fp, fmt, ap);
    va_end(ap);
    printSpace();
}

void printSpace()
{
    fprintf(fp, "\n");
}

void endLog()
{
    fclose(fp);
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

