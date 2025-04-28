#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct Tree
{
    Node* root;
    size_t size;
} Tree;

struct Node
{
    int data;
    Node* parent;
    Node* left;
    Node* right;
};

Node* node_create(int data)
{
    Node* node = malloc(sizeof(Node));

    *node = (Node){ .data = data };

    return node;
}

Tree* t_create()
{
    Tree* tree = calloc(1, sizeof(Tree));

    return tree;
}

__attribute__((nonnull)) void t_destroy(Tree* tree)
{

}

Node* insert(Tree* tree, int data)
{
    if (!tree->root)
    {
        *tree = (Tree){ .root = node_create(data), .size = 1 };
        return tree->root;
    }
    
    Node** current = &tree->root;
    Node* parent = nullptr;

    while (*current)
    {
        parent = *current;
        if (data < (*current)->data)
        {
            current = &(*current)->left;
            
        }
        
    }
    
}