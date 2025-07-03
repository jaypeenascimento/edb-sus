#include "waitlist_manager.h"
#include "../commons.h"
#include "../extensions/logger.h"
#include "../structures/deque.h"
#include <stdlib.h>

WaitlistManager *newWaitlistManager() {
  WaitlistManager *manager = malloc(sizeof(WaitlistManager));
  if (!manager) {
    return NULL;
  }

  manager->waitlist = dequeCreate();
  if (!manager->waitlist) {
    free(manager);
    return NULL;
  }

  return manager;
}

bool _checkWlIsNull(WaitlistManager *manager) {
  if (!manager || !manager->waitlist) {
    logMessage("[ERROR] Gerenciador da lista de espera ou seu deque está NULL");
    return true;
  }
  return false;
}

bool waitlistManagerProcess(WaitlistManager *manager, ManagerContext *ctx) {
    (void)manager;
    (void)ctx;
    return false;
}

bool waitlistManagerCanInsert(WaitlistManager *manager) {
  if (_checkWlIsNull(manager)) {
    return false;
  }

  return manager->waitlist->itemCount < MAX_WAITLIST_SIZE;
}

void waitlistManagerInsertPatient(WaitlistManager *manager, Patient *p) {
  if (!waitlistManagerCanInsert(manager)) {
    return logMessage(
        "[ERROR] Não é possível inserir paciente na lista de espera: "
        "capacidade máxima atingida");
  }

  if (p->priority >= HIGH_PRIORITY_THRESHOLD) {
    dequeEnqueueFront(manager->waitlist, p);
  } else {
    dequeEnqueueBack(manager->waitlist, p);
  }
}

Patient *waitlistManagerRemovePatient(WaitlistManager *manager) {
  if (_checkWlIsNull(manager)) {
    return NULL;
  }

  Patient *first = (Patient *)dequePeekFront(manager->waitlist);
  Patient *last = (Patient *)dequePeekBack(manager->waitlist);

  if (!first || !last) {
    logMessage("[ERROR] Não há pacientes na lista de espera");
    return NULL;
  }

  if (first->priority >= last->priority) {
    return (Patient *)dequeDequeueFront(manager->waitlist);
  } else {
    return (Patient *)dequeDequeueBack(manager->waitlist);
  }
}
