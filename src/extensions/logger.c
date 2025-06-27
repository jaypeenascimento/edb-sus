#include "logger.h"

#include <stdarg.h>
#include <stdio.h>

FILE *openLogFile(const char *filename) {
    return fopen(filename, "w");
}

void closeLogFile(FILE *logFile) {
    if (logFile)
        fclose(logFile);
}

void logPatientInfoList(InfoNode *head, int index, FILE *logFile) {
    char logStr[256];
    snprintf(logStr, sizeof(logStr),
             "Inserted patient: [%s, %s, %s, %s, %s, %s, %s] at index %d\n",
             head->info, head->next ? head->next->info : "",
             head->next && head->next->next ? head->next->next->info : "",
             head->next && head->next->next && head->next->next->next
                 ? head->next->next->next->info
                 : "",
             head->next && head->next->next && head->next->next->next &&
                     head->next->next->next->next
                 ? head->next->next->next->next->info
                 : "",
             head->next && head->next->next && head->next->next->next &&
                     head->next->next->next->next &&
                     head->next->next->next->next->next
                 ? head->next->next->next->next->next->info
                 : "",
             head->next && head->next->next && head->next->next->next &&
                     head->next->next->next->next &&
                     head->next->next->next->next->next &&
                     head->next->next->next->next->next->next
                 ? head->next->next->next->next->next->next->info
                 : "",
             index);

    printf("%s", logStr);

    if (logFile) {
        fprintf(logFile, "%s", logStr);
    }
}

void logMessage(FILE *logFile, const char *format, ...) {
    va_list args;

    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (logFile) {
        va_start(args, format);
        vfprintf(logFile, format, args);
        va_end(args);
        fflush(logFile);
    }
}