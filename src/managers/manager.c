#include "manager.h"
#include <stdlib.h>

ManagerContext *new_manager_context() {
  ManagerContext *ctx = malloc(sizeof(ManagerContext));
  if (ctx == NULL) {
    return NULL;
  }

  return ctx;
}
