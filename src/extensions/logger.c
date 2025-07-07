#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

FILE *singletonLogFileDescriptor = NULL;
const char *LogFileFilePath = "./data/out/processamento.log";

FILE *openLogFile(const char *filename) {
    FILE *logFile = fopen(filename, "w");

    if (!logFile) {
        logMessage("[ERROR] Erro ao abrir o arquivo de log!");
    }

    return logFile;
}

FILE *LogFile() {
    if (singletonLogFileDescriptor) {
        return singletonLogFileDescriptor;
    }

    singletonLogFileDescriptor = openLogFile(LogFileFilePath);
    return singletonLogFileDescriptor;
}

void closeLogFile() {
    FILE *logFile = LogFile();

    if (logFile)
        fclose(logFile);
}

void logMessage(const char *format, ...) {
    FILE *logFile = LogFile();
    if (!logFile) {
        return;
    }

    va_list args;
    va_start(args, format);

    va_list argsCopy;
    va_copy(argsCopy, args);

    vprintf(format, args);
    printf("\n");

    vfprintf(logFile, format, argsCopy);
    fprintf(logFile, "\n");

    fflush(logFile);

    va_end(argsCopy);
    va_end(args);
}