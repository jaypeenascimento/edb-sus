#include "waitlist_manager.h"
#include <stdlib.h>

WaitlistManager *new_waitlist_manager() {
  WaitlistManager *manager = malloc(sizeof(WaitlistManager));
  if (!manager) {
    return NULL;
  }

  manager->waitlist = deque_create();
  if (!manager->waitlist) {
    free(manager);
    return NULL;
  }

  return manager;
}
