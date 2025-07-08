#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "src/extensions/filereader.h"
#include "src/extensions/logger.h"
#include "src/managers/bedlist_manager.h"
#include "src/managers/discharge_manager.h"
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
    DischargeManager *d = newDischargeManager();
    ManagerContext *ctx = newManagerContext(wl, bl, d);

    int round = 1;

    while (1) {
        logMessage("------ Rodada %d-----", round);
        bool blreturn = BedlistManagerProcess(bl, ctx);
        bool wlreturn = waitlistManagerProcess(wl, ctx);

        Patient *randomPatient = patientDataManagerGetRandomPatient(hashmap);

        if (randomPatient) {
            randomPatient->attended = 1;

            if (waitlistManagerCanInsert(wl)) {
                waitlistManagerInsertPatient(wl, randomPatient);
                logMessage(
                    "ESPERA - %s (prioridade %d)",
                    randomPatient->id, randomPatient->priority);
                patientRemove(hashmap, randomPatient->id);
            }
        } else {
            // logMessage(
                // "[INFO] Não há mais pacientes para transferir do hashmap.");
        }


        sleep(0);

        if (!(wlreturn || blreturn || randomPatient != NULL)) {
            logMessage("[INFO] Finalizando ciclos. Gerenciadores ociosos");
            break;
        }

        round++;
    }

    closeLogFile();
    return 0;
}
