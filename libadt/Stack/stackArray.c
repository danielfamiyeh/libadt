#include <stdlib.h>
#include <stdio.h>

struct StackArray
{
    int length;
    int top;
    int* array;
};

struct StackArray* stackArrayConst(int length)
{
    struct StackArray* stack = (struct StackArray*)malloc(sizeof(struct StackArray));
    stack->length = length;
    stack->top = 0;
    stack->array = calloc(length, sizeof(int));

    return stack;
}

int stackArrayIsEmpty(struct StackArray* stack)
{
    return (stack->top == 0) ? 1 : 0;
}

int stackArrayIsFull(struct StackArray* stack)
{
    return (stack->top == stack->length) ? 1 : 0;
}

int stackArrayPush(struct StackArray* stack, int entity)
{
    if(!stackArrayIsFull(stack))
    {
        stack->array[stack->top] = entity;
        stack->top++;
        return 1;
    }
    else
    {
        printf("Error - Stack is full.\n");
        return 0;
    }
    
}

int stackArrayPop(struct StackArray* stack)
{
    if(stack->top > 0)
    {
        stack->array[stack->top] = 0; //All indexes are intialised to 0 on instantiation anyway.
        stack->top--;
    }
}

void stackArrayPrint(struct StackArray* stack)
{
    for(int i=0; i<stack->top; i++)
    {
        printf("Index: %d\nItem: %d\n\n", i, stack->array[i]);
    }
}

void stackArrayDest(struct StackArray* stack)
{
   free(stack->array);
   free(stack);
}