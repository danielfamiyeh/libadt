//Opaque doubly-linked list struct type definition
struct DoubleList;

struct DoubleList* doubleListConst();

void doubleListDest(struct DoubleList* list);

int doubleListAdd(struct DoubleList* list, int entity);

int doubleListAddFront(struct DoubleList* list, int entity);

int doubleListRem(struct DoubleList* list, int index);

void doubleListPrint(struct DoubleList* list);

int doubleListSearch(struct DoubleList* list, int val);

int doubleListGetSize(struct DoubleList* list);

int doubleListIsEmpty(struct DoubleList* list);