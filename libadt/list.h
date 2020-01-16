struct List;

//constructor
struct List* listConst();

//display list items
void printList(struct List* list);

//append to list
void listAdd(struct List* list, int item);

//remove from list
void listRem(struct List* list, int index);

//read from list into var
void listRead(struct List* list, int index, int* entity);

//free list from memory
void listDest(struct List* list);

//search through list for item
int listSearch(struct List* list, int item);

//get size of list
int listSize(struct List* list);

//return whether or not list is empty
int listIsEmpty(struct List* list);