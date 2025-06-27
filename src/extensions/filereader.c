#include "filereader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h"

void loadPatients(HashTable *hashTable, const char *filename, FILE *logFile) {
    logMessage(logFile, "[INFO] Iniciando o carregamento dos pacientes...\n");

    FILE *csv = fopen(filename, "r");
    if (!csv) {
        logMessage(logFile, "[ERROR] Erro ao abrir o arquivo de pacientes: %s\n",
                   filename);
        return;
    }

    char line[256];
    fgets(line, sizeof(line), csv);

    while (fgets(line, sizeof(line), csv)) {
        char id[16], name[64], cpf[16], gender;
        int age, priority, attended;
        sscanf(line, "%15[^;];%63[^;];%d;%c;%15[^;];%d;%d", id, name, &age,
               &gender, cpf, &priority, &attended);

        insertPatient(hashTable, id, name, age, gender, cpf, priority, attended,
                      logFile);
    }

    fclose(csv);

    logMessage(logFile, "[INFO] Carregamento dos pacientes finalizado.\n");
}