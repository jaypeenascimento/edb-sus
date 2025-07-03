#include "bedlist_manager.h"
#include <stdlib.h>

#include "../commons.h"
#include "../extensions/logger.h"
#include <stdbool.h>

BedlistManager *NewBedlistManager() {
  BedlistManager *manager = malloc(sizeof(BedlistManager));
  if (!manager) {
    return NULL;
  }

  for (int i = 0; i < MAX_BEDLIST_SIZE; i++) {
    manager->bedlist[i] = NULL;
  }

  return manager;
}

bool _checkBlIsNull(BedlistManager *manager) {
  if (!manager) {
    logMessage("[ERROR] Gerenciador da lista de leitos está NULL");
    return true;
  }

  return false;
}

bool _checkBlIsEmpty(BedlistManager *manager) {
  if (_checkBlIsNull(manager)) {
    logMessage("[ERROR] Chamou _checkBlIsEmpty com o manager vazio.");
    return false;
  }

  for (int i = 0; i < MAX_BEDLIST_SIZE; i++) {
    if (manager->bedlist[i] != NULL) {
      return false;
    }
  }
  return true;
}

bool BedlistManagerProcess(BedlistManager *manager, ManagerContext *ctx) {
  // Implement the logic to process the bed list manager
  return false;
}

bool BedlistManagerCheckAvailableBed(BedlistManager *manager) {
  if (_checkBlIsNull(manager)) {
    return false;
  }

  for (int i = 0; i < MAX_BEDLIST_SIZE; i++) {
    if (manager->bedlist[i] == NULL) {
      return true;
    }
  }
  return false;
}

void BedlistManagerOccupyBed(BedlistManager *manager, Patient *p) {
  if (_checkBlIsNull(manager)) {
    return;
  }

  for (int i = 0; i < MAX_BEDLIST_SIZE; i++) {
    if (manager->bedlist[i] == NULL) {
      manager->bedlist[i] = p;
      logMessage("[INFO] Paciente %s ocupado no leito %d", p->name, i);
      return;
    }
  }

  logMessage("[ERROR] Não há leitos disponíveis para o paciente %s", p->name);
}

Patient *BedlistManagerDischargeRandomPatient(BedlistManager *manager) {
  if (_checkBlIsNull(manager)) {
    return NULL;
  }

  if (_checkBlIsEmpty(manager)) {
    logMessage("[ERROR] Não há pacientes para liberar");
    return NULL;
  }

  // Select a random index between 0 and MAX_BEDLIST_SIZE - 1
  // if patient is not NULL, discharge it
  // (This may not discharge a patient (intentionally) if there is empty beds)
  for (int i = 0; i < MAX_BEDLIST_SIZE; i++) {
    int randomIndex = rand() % MAX_BEDLIST_SIZE;

    if (manager->bedlist[randomIndex] != NULL) {
      Patient *p = manager->bedlist[randomIndex];
      manager->bedlist[randomIndex] = NULL;
      logMessage("[INFO] Paciente %s liberado do leito %d", p->name,
                 randomIndex);
      return p;
    }
  }

  logMessage("[INFO] Nenhum paciente foi sorteado para alta");
  return NULL;
}
