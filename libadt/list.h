struct SingleList;

//constructor
struct SingleList* singleListConst();

//destructor
void singleListDest(struct SingleList* list);

int singleListRead(struct SingleList* list, int index, int* varPtr);

int singleListAdd(struct SingleList* list, int entity);

int singleListAddFront(struct SingleList* list, int entity);

int singleListRem(struct SingleList* list, int index);

void singleListPrint(struct SingleList* list);

int singleListGetSize(struct SingleList* list);

int singleListIsEmpty(struct SingleList* list);