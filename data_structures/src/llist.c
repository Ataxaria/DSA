#include "llist.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

// THIS CODE SUCKS ASS

/*
to-do:
- recursive search works
- delete by value
*/

struct Node 
{
    int data;
    Node* next;
    Node* prev;
};

typedef struct LinkedList 
{
    Node* head;
    Node* tail;
    int size;
} LinkedList;

Node* node_create(int data) 
{
    Node* node = malloc(sizeof(Node));

    node->data = data;
    node->next = nullptr;
    node->prev = nullptr;

    return node;
}

LinkedList* ll_create()
{
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;

    return list;
}

void ll_destroy(LinkedList* list)
{
    Node* current = list->head;
    
    while (current)
    {
        Node* temp = current->next;
        free(current);
        current = temp;
    }
    
    free(list);
}

void ll_insert(LinkedList* list, int data, int index)
{
    if (index < 0 || index > list->size)
    {
        puts("Invalid index.");
        return;
    }

    Node* new_node = node_create(data);
    Node** current = &list->head;

    if (list->head == nullptr)
    {
        list->head = list->tail = new_node;
    } 
    else
    {
        for (int i = 0; i < index; i++)
        {
            current = &(*current)->next;
        }

        new_node->next = *current;

        if (*current)
        {
            new_node->prev = (*current)->prev;
            (*current)->prev = new_node;
        }
        else
        {
            new_node->prev = list->tail;
            list->tail = new_node;
        }
        
        *current = new_node;

        if (index == 0)
        {
            list->head = new_node;
        }
        
    }
    
    list->size++;
}

void ll_delete(LinkedList* list, int index)
{
    if ((index < 0 || index >= list->size) || list->head == nullptr)
    {
        puts("Invalid index.");
        return;
    }

    Node** current = &list->head;

    for (int i = 0; i < index; i++)
    {
        current = &(*current)->next;
    }

    Node* target = *current;
    *current = target->next;

    if (target->next)
    {
        target->next->prev = target->prev;
    }
    else
    {
        list->tail = target->prev;
    }

    if (index == 0)
    {
        list->head = target->next;
        if (list->head)
        {
            list->head->prev = nullptr;
        }
    }
    
    free(target);
    list->size--;
}

struct SearchResult { Node** nodeptr; int index; bool found; } ll_search(LinkedList* list, int value)
{
    Node** current = &list->head;
    int index = 0;
    
    while (*current)
    {
        if ((*current)->data == value)
        {
            break;
        }
        current = &(*current)->next;
        index++;
    }

    return (struct SearchResult){ 
        .nodeptr = current, 
        .index = (index == list->size) ? -1 : index,
        .found = (index != list->size)  // since index == list->size at end of loop
    };

}

void ll_print(LinkedList* list)
{
    Node** current = &list->head;
    while (*current)
    {
        printf("%d\t", (*current)->data);
        current = &(*current)->next;
    }
    printf("\n");
}
