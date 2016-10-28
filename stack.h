/* 
 * File:   stack.h
 * Author: Petri Kallio
 *
 * Created on October 28, 2016, 10:28 AM
 */

#include "linked_list.h"

#ifndef STACK_H
#define	STACK_H

struct stack_t {
    LinkedList *stack;
} typedef Stack;

Stack *create_stack();
int stack_empty(Stack *S);
int stack_size(Stack *S);
void stack_clear(Stack *S);
void stack_push(Stack *S, int key);
int stack_pop(Stack *S);
int stack_peek(Stack *S);

#endif	/* STACK_H */

