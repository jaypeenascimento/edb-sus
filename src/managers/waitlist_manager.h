#ifndef WAITLIST_MANAGER_H
#define WAITLIST_MANAGER_H

#include "../structures/deque.h"
#include "manager.h"

typedef struct WaitlistManager {
  Deque *waitlist;
} WaitlistManager;

WaitlistManager *new_waitlist_manager();

bool waitlist_manager_process(WaitlistManager *manager, ManagerContext *ctx);

#endif
