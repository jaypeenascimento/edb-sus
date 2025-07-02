#include "waitlist_manager.h"
#include "../commons.h"
#include "../extensions/logger.h"
#include "../structures/deque.h"
#include <stdlib.h>

WaitlistManager *new_waitlist_manager() {
  WaitlistManager *manager = malloc(sizeof(WaitlistManager));
  if (!manager) {
    return NULL;
  }

  manager->waitlist = deque_create();
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

bool waitlist_manager_process(WaitlistManager *manager, ManagerContext *ctx) {
  return false;
}

bool WaitlistManagerCanInsert(WaitlistManager *manager) {
  if (_checkWlIsNull(manager)) {
    return false;
  }

  return manager->waitlist->itemCount < MAX_WAITLIST_SIZE;
}

void WaitListManagerInsertPatient(WaitlistManager *manager, Patient *p) {
  if (!WaitlistManagerCanInsert(manager)) {
    return logMessage(
        "[ERROR] Não é possível inserir paciente na lista de espera: "
        "capacidade máxima atingida");
  }

  if (p->priority >= HIGH_PRIORITY_THRESHOLD) {
    deque_enqueuefront(manager->waitlist, p);
  } else {
    deque_enqueueback(manager->waitlist, p);
  }
}

Patient *WaitListManagerRemovePatient(WaitlistManager *manager) {
  if (_checkWlIsNull(manager)) {
    return NULL;
  }

  Patient *first = (Patient *)deque_peekfront(manager->waitlist);
  Patient *last = (Patient *)deque_peekback(manager->waitlist);

  if (!first || !last) {
    logMessage("[ERROR] Não há pacientes na lista de espera");
    return NULL;
  }

  if (first->priority >= last->priority) {
    return (Patient *)deque_dequeuefront(manager->waitlist);
  } else {
    return (Patient *)deque_dequeueback(manager->waitlist);
  }
}
