struct SingleList;

//constructor
struct SingleList* singleListConst();

//destructor
void singleListDest(struct SingleList* list);

int singleListAdd(struct SingleList* list, int entity);

int singleListAddFront(struct SingleList* list, int entity);

int singleListRead(struct SingleList* list, int index, int* varPtr);

int singleListRem(struct SingleList* list, int index);

void singleListPrint(struct SingleList* list);

int singleListSearch(struct SingleList* list, int val);

int singleListGetSize(struct SingleList* list);

int singleListIsEmpty(struct SingleList* list);