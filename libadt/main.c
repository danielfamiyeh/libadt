#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct SingleList* l;
    int i;
    l = singleListConst();

    //List is empty
    printf("\n%d\n", singleListIsEmpty(l));

    //Add to back of list
    singleListAdd(l, 5);
    singleListAdd(l, 2);

    //List is not empty
    printf("\n%d\n\n", singleListIsEmpty(l));

    //Print list content
    singleListPrint(l);
    printf("\n");

    //Add to front of list
    singleListAddFront(l,10);
    singleListPrint(l);

    //Reading Variable
    singleListRead(l, 1, &i);
    printf("\nItem Read: %d\n", i);

    //Get list size
    printf("\nSize: %d\n", singleListGetSize(l));
    
    singleListRem(l, 1);
    singleListPrint(l);

    singleListDest(l);
   // singleListPrint(l);
}
