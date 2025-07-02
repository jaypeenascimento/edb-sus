#include "src/extensions/filereader.h"
#include "src/extensions/logger.h"
#include "src/managers/manager.h"
#include "src/managers/waitlist_manager.h"
#include "src/structures/hashmap.h"

#include <unistd.h>

int main() {
  HashMap *hashmap = hashmap_create();
  loadPatients(hashmap, "./data/in/pacientes.csv");

  WaitlistManager *wl = new_waitlist_manager();
  ManagerContext *ctx = new_manager_context(wl);

  while (1) {
    bool wlreturn = waitlist_manager_process(wl, ctx);

    sleep(2);

    // Exit loop if all managers return false.
    if (!wlreturn) {
      logMessage("[INFO] Finalizando ciclos dado que os gerenciadores estão "
                 "todos ociosos");
      break;
    }
  }

  closeLogFile();
  return 0;
}
