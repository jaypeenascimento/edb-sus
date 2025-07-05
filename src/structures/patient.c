#include "patient.h"

#include <stdlib.h>
#include <string.h>

Patient *createPatient(const char *id, const char *name, int age, char gender,
                       const char *cpf, int priority, int attended) {
    Patient *patient = (Patient *)malloc(sizeof(Patient));
    if (!patient) {
        return NULL;
    }

    patient->id = strdup(id);
    patient->name = strdup(name);
    patient->age = age;
    patient->gender = gender;
    patient->cpf = strdup(cpf);
    patient->priority = priority;
    patient->attended = attended;

    return patient;
}
