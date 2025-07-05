#ifndef PATIENTDATA_MANAGER_H
#define PATIENTDATA_MANAGER_H

#include "../commons.h"
#include "../structures/hashmap.h"
#include "../structures/patient.h"

Patient *patientDataManagerGetRandomPatient(HashMap *hashmap);

void patientRemove(HashMap *hashmap, char *key);

#endif