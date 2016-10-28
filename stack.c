#include <stddef.h>
#include <stdlib.h>
#include "stack.h"
#include "linked_list.h"

Stack *create_stack() {
    Stack *stack = malloc(sizeof(Stack));
    
    if (!stack) {
        return NULL;
    }
    
    stack->stack = malloc(sizeof(LinkedList));
    
    if (!stack->stack) {
        free(stack);
        return NULL;
    }
}

int stack_empty(Stack *S) {
    if (S->stack->size == 0) {
        return 1;
    }
    
    return 0;
}

int stack_size(Stack *S) {
    return S->stack->size;
}

void stack_clear(Stack *S) {
    list_clear(S->stack);
}

void stack_push(Stack *S, int key) {
    list_insert(S->stack, key);
}

int stack_pop(Stack *S) {
    int x = list_delete(S->stack, S->stack->head);
    return x;
}

int stack_peek(Stack *S) {
    int x = stack_pop(S);
    stack_push(S, x);
    return x;
}