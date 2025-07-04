#include "manager.h"
#include <stdlib.h>

ManagerContext *newManagerContext(WaitlistManager *wl) {
  ManagerContext *ctx = malloc(sizeof(ManagerContext));
  if (ctx == NULL) {
    return NULL;
  }

  ctx->waitlist_manager = wl;

  return ctx;
}
