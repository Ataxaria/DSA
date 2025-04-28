#ifndef LLIST_H
#define LLIST_H

typedef struct Node Node;
typedef struct LinkedList LinkedList;
typedef struct SearchResult SearchResult;

LinkedList* ll_create();
void ll_destroy(LinkedList* list);

void ll_insert(LinkedList* list, int data, int index);
void ll_delete(LinkedList* list, int index);
SearchResult ll_search(LinkedList* list, int value);

void ll_print(LinkedList* list);

#endif