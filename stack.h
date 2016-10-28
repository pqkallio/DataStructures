/* 
 * File:   stack.h
 * Author: Petri Kallio
 *
 * Created on October 28, 2016, 10:28 AM
 */

#include "linked_list.h"
#include <stddef.h>

#ifndef STACK_H
#define	STACK_H

struct stack_t {
    LinkedList *stack;
} typedef Stack;

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

void stack_push(Stack *S, int k) {
    list_insert(S->stack, k);
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

#endif	/* STACK_H */

