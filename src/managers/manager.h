#ifndef MANAGER_H
#define MANAGER_H

typedef struct WaitlistManager WaitlistManager;
typedef struct BedlistManager BedlistManager;

typedef struct ManagerContext {
  // Temporarily empty struct to represent a manager context.
  // Add any necessary fields for the managers to function here later.
  WaitlistManager *waitlist_manager;
  BedlistManager *bedlistManager;
} ManagerContext;

ManagerContext *newManagerContext(WaitlistManager *wl, BedlistManager *bl);

#endif
