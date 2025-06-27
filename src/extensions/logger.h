#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include "../structures/hashmap.h"

FILE* openLogFile(const char *filename);
void closeLogFile(FILE *logFile);
void logPatientInfoList(InfoNode *head, int index, FILE *logFile);
void logMessage(FILE *logFile, const char *format, ...);

#endif