#include <stdio.h>
#include <stdlib.h>

//Opaque stack struct definition
struct StackArray;

//
struct StackArray* stackArrayConst();

void stackArrayDest();

void stackArrayPrint(struct StackArray* stack);

int stackArrayPush(struct StackArray* stack, int val);

int stackArrayPop(struct StackArray* stack);

int stackArrayIsFull(struct StackArray* stack);

int stackArrayIsEmpty(struct StackArray* stack);
