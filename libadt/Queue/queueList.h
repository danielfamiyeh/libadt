struct QueueList;

struct QueueList* queueListConst();

struct QueueList* queueListDest(struct QueueList* queue);

int queueListPeek(struct QueueList* queue);

int queueListAdd(struct QueueList* queue, int entity);

int queueListRem(struct QueueList* queue);

void queueListPrint(struct QueueList* queue);