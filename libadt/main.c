#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct List* l;
    int i;
    l = listConst();
    listAdd(l,3);
    listAdd(l,7);
    listAdd(l,4);
    listRem(l,1);
    listAdd(l,7);
    printf("%d\n", listSearch(l,-4));
    
    listRead(l,2,&i);
    printf("%d\n", i);
    printList(l);
    listDest(l);
}
