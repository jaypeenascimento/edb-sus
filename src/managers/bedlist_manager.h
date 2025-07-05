#ifndef BEDLIST_MANAGER_H
#define BEDLIST_MANAGER_H

#include "../structures/patient.h"
#include "manager.h"
#include <stdbool.h>

#include "../commons.h"

typedef struct BedlistManager {
  Patient *bedlist[MAX_BEDLIST_SIZE];
} BedlistManager;

BedlistManager *NewBedlistManager();

bool BedlistManagerProcess(BedlistManager *manager, ManagerContext *ctx);

bool BedlistManagerCheckAvailableBed(BedlistManager *manager);

void BedlistManagerOccupyBed(BedlistManager *manager, Patient *p);

Patient *BedlistManagerDischargeRandomPatient(BedlistManager *manager);

#endif
