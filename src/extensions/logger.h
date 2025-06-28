#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

FILE *openLogFile(const char *filename);
void closeLogFile();
void logMessage(const char *format, ...);

#endif
