#include "logger.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *singletonLogFileDescriptor = NULL;
const char *LogFileFilePath = "./data/out/processamento.log";

FILE *openLogFile(const char *filename) {
  FILE *logFile = fopen(filename, "w");

  if (!logFile) {
    logMessage(NULL, "Erro ao abrir o arquivo de log!");
  }

  return logFile;
}

FILE *LogFile() {
  if (singletonLogFileDescriptor) {
    return singletonLogFileDescriptor;
  }

  return openLogFile(LogFileFilePath);
}

void closeLogFile() {
  FILE *logFile = LogFile();

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

void logMessage(const char *format, ...) {
  FILE *logFile = LogFile();
  va_list args;
  va_list args_copy;

  va_start(args, format);
  va_copy(args_copy, args);

  size_t len = strlen(format) + 2;
  char *nlformat = malloc(len);
  sprintf(nlformat, "%s\n", format);

  vprintf(nlformat, args);
  vfprintf(logFile, nlformat, args_copy);

  free(nlformat);
  fflush(logFile);
  va_end(args_copy);
  va_end(args);
}
