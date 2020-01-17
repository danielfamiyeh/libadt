#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "SingleLinkedList/singleLinkedList.h"

int main()
{
    struct SingleList* sll = singleListConst();
    struct DoubleList* list = doubleListConst();
    singleListAdd(sll, 1);
    singleListAddFront(sll, 2);
    singleListAdd(sll, 9);

    printf("%d\n", singleListSearch(sll, 2));

  //  singleListPrint(sll);

    singleListDest(sll);
}
