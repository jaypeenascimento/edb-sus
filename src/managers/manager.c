#include "manager.h"
#include <stdlib.h>

ManagerContext *new_manager_context(WaitlistManager *wl) {
  ManagerContext *ctx = malloc(sizeof(ManagerContext));
  if (ctx == NULL) {
    return NULL;
  }

  ctx->waitlist_manager = wl;

  return ctx;
}
