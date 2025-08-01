#ifndef DISCHARGE_MANAGER_H
#define DISCHARGE_MANAGER_H

#include <stdbool.h>

#include "../structures/patient.h"
#include "../structures/stack.h"

typedef struct DischargeManager {
    Stack *dischargeStack;
} DischargeManager;

DischargeManager *newDischargeManager();

void dischargeManagerDischargePatient(DischargeManager *manager, Patient *p);

#endif
