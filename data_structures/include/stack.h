#ifndef STACK_H
#define STACK_H

typedef struct Stack Stack;

Stack* create_stack(int capacity);

int push(Stack* stack, int argc, ...); 
int pop(Stack* stack);
int peek(Stack* stack);

int get_capacity(Stack* stack);
int get_size(Stack* stack);

Stack* grow(Stack* stack, int growBy);
Stack* shrink(Stack* stack);

bool is_empty(Stack* stack);

#endif