struct List;

struct List* listConst();
void printList(struct List* list);
void listAdd(struct List* list, int item);
void listRem(struct List* list, int index);
void listRead(struct List* list, int index, int* entity);
void listDest(struct List* list);
int listSearch(struct List* list, int entity);