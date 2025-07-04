#ifndef MANAGER_H
#define MANAGER_H

typedef struct WaitlistManager WaitlistManager;

typedef struct ManagerContext {
  // Temporarily empty struct to represent a manager context.
  // Add any necessary fields for the managers to function here later.
  WaitlistManager *waitlist_manager;

} ManagerContext;

ManagerContext *newManagerContext(WaitlistManager *wl);

#endif
