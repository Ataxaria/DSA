#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


/*
to-do:
- make implementation generic
- modernize
*/


typedef struct Stack
{
    int capacity; 
    int stackTop;  // recording top ptr would be better probably
    int* arrPtr;  // use VLA syntax
} Stack;

Stack* create_stack(int capacity)  // needs to be modernized
{
    Stack* stack = malloc(sizeof(Stack));

    stack->capacity = capacity;
    stack->stackTop = -1;
    stack->arrPtr = malloc(sizeof(int) * capacity);  // two mallocs is bad

    return stack;
}

Stack* grow(Stack* stack, int growBy)
{
    int cap = stack->capacity + growBy;
    int* temp = malloc(sizeof(int) * cap);

    memcpy(temp, stack->arrPtr, sizeof(int) * (stack->stackTop + 1));
    free(stack->arrPtr);

    stack->arrPtr = temp;
    stack->capacity = cap;

    return stack;
}

Stack* shrink(Stack* stack)
{
    int cap = stack->capacity / 2;
    int* temp = malloc(sizeof(int) * cap);

    memcpy(temp, stack->arrPtr, sizeof(int) * (stack->stackTop + 1));
    free(stack->arrPtr);

    stack->arrPtr = temp;
    stack->capacity = cap;

    return stack;
}

int push(Stack* stack, int argc, ...)
{
    if (stack->stackTop + argc >= stack->capacity)
    {
        stack = grow(stack, (stack->stackTop + 1 + argc) - stack->capacity);
    }

    va_list args;
    va_start(args, argc);

    for (int i = 0; i < argc; i++)
    {
        int data = va_arg(args, int);

        stack->stackTop++;
        stack->arrPtr[stack->stackTop] = data;
    }
    
    va_end(args);
    return stack->stackTop;
}

bool is_empty(Stack* stack)
{ 
    return stack->stackTop == -1;
}

int pop(Stack* stack)
{
    if (is_empty(stack))
    {
        puts("Stack is empty UNDERFLOW");
        return -1;
    }
    
    int element = stack->arrPtr[stack->stackTop];
    stack->arrPtr[stack->stackTop--] = 0;

    bool underutilized = (stack->capacity % 2 == 0) && (stack->stackTop < stack->capacity / 2);
    
    if (underutilized)
    {
        stack = shrink(stack);
    }
    
    return element;
}

int peek(Stack* stack)
{
    return is_empty(stack) ? -1 : stack->arrPtr[stack->stackTop];
}

int get_capacity(Stack* stack)
{
    return stack->capacity;
}

int get_size(Stack* stack)
{
    return stack->stackTop + 1;
}