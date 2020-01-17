#include <stdio.h>
#include <stdlib.h>

#include "Queue/queueList.h"

int main()
{
    struct QueueList* queue = queueListConst();

    queueListAdd(queue, 3);
    queueListAdd(queue, 9);
    queueListAdd(queue, 1);
    queueListPrint(queue);

    int q = queueListRem(queue);
    printf("%d", queueListPeek(queue));

    queueListPrint(queue);

    queueListDest(queue);
    return 0;
}
