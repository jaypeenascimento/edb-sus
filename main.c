#include <unistd.h>

#include "src/extensions/filereader.h"
#include "src/extensions/logger.h"
#include "src/managers/manager.h"
#include "src/structures/hashmap.h"
#include "src/structures/stack.h"

int main() {
    HashMap *hashmap = hashmap_create();
    loadPatients(hashmap, "./data/in/pacientes.csv");

    // Instantiate the managers
    // WaitlistManager *wl = new_waitlist_manager();
    // PatientlistManager *pl = new_patientlist_manager();
    // FooManager *f = new_foo_manager();
    // BarManager *b = new_bar_manager();

    ManagerContext *ctx = new_manager_context(
        // wl, pl, f, b
    );

    // Each loop is called cycle, loop until all managers return false.
    while (1) {
        // Call all managers
        // bool wlreturn = waitlist_manager_process(wl, ctx);
        // bool plreturn = patientlist_manager_process(pl, ctx);
        // bool freturn = foo_manager_process(f, ctx);
        // bool breturn = bar_manager_process(b, ctx);

        sleep(2);

        // INFO: Exit the loop if all managers return false (False means, they
        // didn't processed anything on this call, so, they were all idle, so,
        // program doesn't have to process more anything).
        //
        // if (!wlreturn && !plreturn && !freturn && !breturn) {
        //   break;
        // }
    }

    closeLogFile();
    return 0;
}