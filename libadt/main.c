#include <stdio.h>
#include <stdlib.h>

#include "Stack/stackArray.h"

int main()
{
    struct StackArray* stack = stackArrayConst(25);

    for(int i=0; i<10; i++)
    {
        stackArrayPush(stack, i);
    }
    stackArrayPrint(stack);
    stackArrayPop(stack);
    stackArrayPrint(stack);

    stackArrayDest(stack);
    return 0;
}
