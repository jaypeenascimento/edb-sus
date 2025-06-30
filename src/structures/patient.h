#ifndef PATIENT_H
#define PATIENT_H
#define _POSIX_C_SOURCE 200809L

#include <stdio.h>

typedef struct Patient {
  char *id;
  char *name;
  int age;
  char gender;
  char *cpf;
  int priority;
  int attended;
} Patient;

Patient *createPatient(const char *id, const char *name, int age, char gender,
                       const char *cpf, int priority, int attended);

#endif
