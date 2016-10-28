/* 
 * File:   linked_list.h
 * Author: Petri Kallio
 *
 * Created on October 28, 2016, 10:35 AM
 */

#ifndef LINKED_LIST_H
#define	LINKED_LIST_H

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

LinkedList *create_list();
ListNode *list_insert(LinkedList *L, int key);
void print_list(LinkedList *L);
int list_delete(LinkedList *L, ListNode *x);
ListNode *list_succ(LinkedList *L, ListNode *x);
ListNode *list_pred(LinkedList *L, ListNode *x);
void list_clear(LinkedList *L);
ListNode *list_max(LinkedList *L);


#endif	/* LINKED_LIST_H */

