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

  return openLogFile(LogFileFilePath);
}

void closeLogFile() {
  FILE *logFile = LogFile();

  if (logFile)
    fclose(logFile);
}

// FIX: This does not cause segmentation fault.
// But it does not print to the log file.
void logMessage(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  printf("\n");
  va_end(args);
}

// void logMessage(const char *format, ...) {
//   FILE *logFile = LogFile();
//   if (!logFile) {
//     return;
//   }
//   va_list args;
//   va_list args_copy;
//   va_copy(args_copy, args);
//   va_start(args, format);
//
//   // Print to stdout with newline
//   vprintf(format, args);
//   printf("\n");
//
//   // Print to log file with newline
//   va_start(args_copy, format);
//   vfprintf(logFile, format, args_copy);
//   fprintf(logFile, "\n");
//   va_end(args_copy);
//
//   fflush(logFile);
//   va_end(args);
// }
