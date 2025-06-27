#include <stdio.h>
#include "src/structures/hashmap.h"
#include "src/extensions/filereader.h"
#include "src/extensions/logger.h"

int main() {
    HashTable hashTable;
    initializeTable(&hashTable);

    FILE *logFile = openLogFile("./data/out/processamento.log");
    if (!logFile) {
        logMessage(NULL, "Erro ao abrir o arquivo de log!\n");
        return 1;
    }

    loadPatients(&hashTable, "./data/in/pacientes.csv", logFile);

    // TODO: Adicionar rotina de processamento de pacientes
    
    closeLogFile(logFile);

    return 0;
}