#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
    struct List* l;
    int i;
    l = listConst(5);

    for(int i=0; i<5; i++)
    {
        listAdd(l,i);
    }    

    listPrintFull(l); // prints [0 1 2 3 4]

    listResize(l,10); 
    listPrintFull(l); // prints [0 1 2 3 4 0 0 0 0 0]

    listResize(l, 7); 
    listPrintFull(l); // prints [0 1 2 3 4 0 0]

    listResize(l,1); 
    listPrintFull(l); // prints [0 1 2 3 4]

    listTruncate(l,1);
    listPrintFull(l);

    listDest(l);
}
