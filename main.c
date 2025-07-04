#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "src/extensions/filereader.h"
#include "src/extensions/logger.h"
#include "src/managers/bedlist_manager.h"
#include "src/managers/manager.h"
#include "src/managers/patientdata_manager.h"
#include "src/managers/waitlist_manager.h"
#include "src/structures/hashmap.h"

int main() {
  srand(time(NULL));

  HashMap *hashmap = hashmapCreate();
  loadPatients(hashmap, "./data/in/pacientes.csv");

  WaitlistManager *wl = newWaitlistManager();
  BedlistManager *bl = NewBedlistManager();
  ManagerContext *ctx = newManagerContext(wl);

  while (1) {
    // Sorteia um paciente do hashmap usando o patientdata_manager
    Patient *randomPatient = patientDataManagerGetRandomPatient(hashmap);
    if (randomPatient) {
      waitlistManagerInsertPatient(wl, randomPatient);
      logMessage("[INFO] Paciente transferido do hashmap para o deque: %s",
                 randomPatient->name);
      patientRemove(hashmap, randomPatient->id);
    } else {
      logMessage("[INFO] Não há mais pacientes para transferir do hashmap.");
    }

    bool wlreturn = waitlistManagerProcess(wl, ctx);
    bool blreturn = BedlistManagerProcess(bl, ctx);

    sleep(2);

    // Exit loop if all managers return false.
    if (!(wlreturn || blreturn)) {
      logMessage("[INFO] Finalizando ciclos dado que os gerenciadores estão "
                 "todos ociosos");
      break;
    }
  }

  closeLogFile();
  return 0;
}
