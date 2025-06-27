#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>

typedef struct Patient {
    char *id;
    char *name;
    int age;
    char gender;
    char *cpf;
    int priority;
    int attended;
}

#endif
