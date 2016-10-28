/* 
 * File:   linked_list.h
 * Author: Petri Kallio
 *
 * Created on October 28, 2016, 10:35 AM
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

#include <stddef.h>
#include <math.h>

typedef struct list_node_t ListNode;
typedef struct linked_list_t LinkedList;

struct list_node_t {
    int key;
    ListNode *next;
    ListNode *prev;
};

struct linked_list_t {
    int size;
    ListNode *head;
};

LinkedList *create_list() {
    LinkedList *L = malloc(sizeof(LinkedList));
    
    if (!L) {
        return NULL;
    }
    
    L->head = NULL;
    L->size = 0;
}

ListNode *list_insert(LinkedList *L, int k) {
    ListNode *node = malloc(sizeof(ListNode));
    
    if (!node) {
        return NULL;
    }
    
    node->key = k;
    
    if (L->head == NULL) {
        node->next = node;
        node->prev = node;
        L->head = node;
    } else {
        node->next = L->head;
        node->prev = L->head->prev;
        node->prev->next = node;
        L->head->prev = node;
        L->head = node;
    }
    
    L->size++;
    return node;
}

void print_list(LinkedList *L) {
    ListNode *x = L->head;
    printf("%i, ", x->key);
    x = x->next;
    
    while (x != L->head) {
        printf("%i, ", x->key);
        x = x->next;
    }
    
    printf("\n");
}

int list_delete(LinkedList *L, ListNode *x) {
    if (x == L->head && L->size == 1) {
        L->head = NULL;
    } else {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        if (x == L->head) {
            L->head = x->next;
        }
    }
    int key = x->key;
    free(x);
    L->size--;
    return key;
}

ListNode *list_succ(LinkedList *L, ListNode *x) {
    ListNode *y = L->head;
    ListNode *succ = NULL;
    if (y != x && y->key > x->key) {
        succ = y;
    }
    
    y = y->next;
    
    while (y != L->head) {
        if (y != x && y->key > x->key) {
            if (succ == NULL) {
                succ = y;
            } else if (abs(x->key - y->key) < abs(x->key - succ->key)) {
                succ = y;
            }
        }
        
        y = y->next;
    }
    
    return succ;
}

ListNode *list_pred(LinkedList *L, ListNode *x) {
    ListNode *y = L->head;
    ListNode *pred = NULL;
    if (y != x && y->key < x->key) {
        pred = y;
    }
    
    y = y->next;
    
    while (y != L->head) {
        if (y != x && y->key < x->key) {
            if (pred == NULL) {
                pred = y;
            } else if (abs(x->key - y->key) < abs(x->key - pred->key)) {
                pred = y;
            }
        }
        
        y = y->next;
    }
    
    return pred;
}

ListNode *list_max(LinkedList *L) {
    ListNode *max = L->head;
    
    if (L->head == NULL) {
        return NULL;
    }
    
    ListNode *x = max->next;
    
    while (x != L->head) {
        if (x->key > max->key) {
            max = x;
        }
        x = x->next;
    }
    
    return max;
}

#endif	/* LINKED_LIST_H */

