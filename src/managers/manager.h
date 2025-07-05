#ifndef MANAGER_H
#define MANAGER_H

typedef struct WaitlistManager WaitlistManager;
typedef struct BedlistManager BedlistManager;
typedef struct DischargeManager DischargeManager;

typedef struct ManagerContext {
  // Temporarily empty struct to represent a manager context.
  // Add any necessary fields for the managers to function here later.
  WaitlistManager *waitlist_manager;
  BedlistManager *bedlistManager;
  DischargeManager *dischargeManager;
} ManagerContext;

ManagerContext *newManagerContext(WaitlistManager *wl, BedlistManager *bl,
                                  DischargeManager *d);

#endif
