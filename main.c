/* 
 * File:   main.c
 * Author: Petri Kallio
 *
 * Created on October 28, 2016, 10:27 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "stack.h"
/*
 * 
 */
int main(int argc, char** argv) {
    LinkedList *L = malloc(sizeof(LinkedList));
    
    if (!L) {
        printf("Unable to allocate!");
        return (EXIT_FAILURE);
    }
    
    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int v_length = 7;
    int i;
    for (i = 0; i < v_length; i++) {
        list_insert(L, values[i]);
    }
    
    ListNode *x = list_insert(L, 10);
    ListNode *x2 = list_insert(L, 2);
    
    print_list(L);
    
    list_delete(L, x);
    
    print_list(L);
    
    ListNode *succ_of_x2 = list_succ(L, x2);
    
    if (succ_of_x2) {
        printf("Successor of %i is %i\n", x2->key, succ_of_x2->key);
    }
    
    ListNode *pred_of_x2 = list_pred(L, x2);
    
    if (pred_of_x2) {
        printf("Predecessor of %i is %i\n", x2->key, pred_of_x2->key);
    }
    
    ListNode *pred_pred_of_x2 = list_pred(L, pred_of_x2);
    
    if (!pred_pred_of_x2) {
        printf("%i has no predecessor\n", pred_of_x2->key);
    }
    
    ListNode *max = list_max(L);
    
    if (max) {
        printf("Max is %i\n", max->key);
    }
    
    printf("List size: %i\n", L->size);
    list_clear(L);
    printf("List size: %i\n", L->size);
    
    Stack *S = create_stack();
    
    if (stack_empty(S)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
    
    stack_push(S, 3);
    
    if (stack_empty(S)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
    
    printf("Peek: %i", stack_peek(S));
    
    if (stack_empty(S)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
    
    printf("Pop: %i", stack_pop(S));
    
    if (stack_empty(S)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
    
    stack_clear(S);
    list_clear(L);
    
    free(S);
    free(L);
    
    return (EXIT_SUCCESS);
}

