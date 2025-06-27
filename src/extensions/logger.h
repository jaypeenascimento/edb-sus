#ifndef LOGGER_H
#define LOGGER_H

#include "../structures/hashmap.h"
#include <stdio.h>

FILE *openLogFile(const char *filename);
void closeLogFile();
void logPatientInfoList(InfoNode *head, int index, FILE *logFile);
void logMessage(const char *format, ...);

#endif
