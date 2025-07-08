#include "discharge_manager.h"

#include "../extensions/logger.h"
#include "../structures/stack.h"

DischargeManager *newDischargeManager() {
    DischargeManager *manager = malloc(sizeof(DischargeManager));
    if (!manager) {
        return NULL;
    }

    Stack *dischargeStack = stackCreate();
    if (dischargeStack == NULL) {
        logMessage("[ERROR] Falha ao criar a pilha de alta");
        free(manager);
        return NULL;
    }

    manager->dischargeStack = dischargeStack;

    return manager;
}

void dischargeManagerDischargePatient(DischargeManager *manager, Patient *p) {
    if (!manager || !manager->dischargeStack) {
        logMessage("[ERROR] Gerenciador de alta ou pilha de alta está NULL");
        return;
    }

    if (p == NULL) {
        logMessage("CHECKED for null at dmdp");
        return;
    }

    stackPush(manager->dischargeStack, p);
    logMessage("ALTA - %s (%s)", p->id, p->name);

    p->attended = 1;
}
