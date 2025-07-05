#include "manager.h"
#include <stdlib.h>

ManagerContext *newManagerContext(WaitlistManager *wl, BedlistManager *bl,
                                  DischargeManager *d) {
  ManagerContext *ctx = malloc(sizeof(ManagerContext));
  if (ctx == NULL) {
    return NULL;
  }

  ctx->waitlist_manager = wl;
  ctx->bedlistManager = bl;
  ctx->dischargeManager = d;

  return ctx;
}
