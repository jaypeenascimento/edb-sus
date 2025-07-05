#ifndef WAITLIST_MANAGER_H
#define WAITLIST_MANAGER_H

#include <stdbool.h>

#include "../structures/deque.h"
#include "../structures/patient.h"
#include "manager.h"

typedef struct WaitlistManager {
    Deque *waitlist;
} WaitlistManager;

WaitlistManager *newWaitlistManager();

bool waitlistManagerProcess(WaitlistManager *manager, ManagerContext *ctx);

bool waitlistManagerCanInsert(WaitlistManager *manager);

void waitlistManagerInsertPatient(WaitlistManager *manager, Patient *p);

Patient *waitlistManagerRemovePatient(WaitlistManager *manager);
#endif
