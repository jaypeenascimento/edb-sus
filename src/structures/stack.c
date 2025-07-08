#include "stack.h"

#include "../extensions/logger.h"

Stack *stackCreate() {
    Stack *stack = (Stack *)malloc(sizeof(Stack));

    if (stack) {
        stack->list = linkedlistCreate();
        // logMessage("[INFO] Pilha criada com sucesso.");
    } else {
        logMessage("[ERROR] Erro ao criar a pilha.");
    }

    return stack;
}

void stackPush(Stack *stack, void *data) {
    if (!stack || !stack->list) {
        logMessage("[ERROR] Erro ao empilhar: pilha não inicializada.");
        return;
    }

    LinkedListNode *node = (LinkedListNode *)malloc(sizeof(LinkedListNode));

    if (!node) {
        logMessage("[ERROR] Erro ao empilhar: falha ao alocar nó.");
        return;
    }

    node->data = data;
    node->next = stack->list->head;
    stack->list->head = node;
}

void *stackPop(Stack *stack) {
    if (!stack || !stack->list || !stack->list->head) {
        logMessage(
            "[ERROR] Erro ao desempilhar: pilha vazia ou não inicializada.");
        return NULL;
    }

    LinkedListNode *node = stack->list->head;
    void *data = node->data;
    stack->list->head = node->next;

    free(node);

    logMessage("[INFO] Elemento desempilhado com sucesso.");

    return data;
}

void *stackPeek(Stack *stack) {
    if (!stack || !stack->list || !stack->list->head) {
        logMessage(
            "[ERROR] Erro ao acessar o topo: pilha vazia ou não inicializada.");
        return NULL;
    }

    logMessage("[INFO] Topo da pilha acessado com sucesso.");

    return stack->list->head->data;
}

int stackIsEmpty(Stack *stack) {
    int empty = (!stack || !stack->list || !stack->list->head);

    logMessage("[INFO] Verificação de pilha vazia: %s.",
               empty ? "vazia" : "não vazia");

    return empty;
}

void stackFree(Stack *stack) {
    if (!stack) {
        logMessage("[ERROR] Erro ao liberar pilha: pilha não inicializada.");
        return;
    }

    linkedlistFree(stack->list);
    free(stack);

    logMessage("[INFO] Pilha liberada com sucesso.");
}
