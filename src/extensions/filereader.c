#include "filereader.h"

#include "../structures/patient.h"
#include "logger.h"
#include <stdio.h>

void loadPatients(HashMap *hashmap, const char *filename) {
  logMessage("[INFO] Iniciando o carregamento dos pacientes...");

  FILE *csv = fopen(filename, "r");
  if (!csv) {
    logMessage("[ERROR] Erro ao abrir o arquivo de pacientes: %s", filename);
    return;
  }

  char line[256];
  fgets(line, sizeof(line), csv);

  while (fgets(line, sizeof(line), csv)) {
    char id[16], name[64], cpf[16], gender;
    int age, priority, attended;
    sscanf(line, "%15[^;];%63[^;];%d;%c;%15[^;];%d;%d", id, name, &age, &gender,
           cpf, &priority, &attended);

    Patient *patient =
        createPatient(id, name, age, gender, cpf, priority, attended);
    hashmap_insert(hashmap, id, patient);

    logMessage("Paciente inserido: [ID: %s, Nome: %s, Idade: %d, Sexo: %c, "
               "CPF:  %s, Prioridade: %d, Atendido: %d] no índice \"%s\"",
               id, name, age, gender, cpf, priority, attended, id);
  }

  fclose(csv);

  logMessage("[INFO] Carregamento dos pacientes finalizado.");
}
