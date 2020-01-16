#include <stdlib.h>
#include <stdio.h>

#define ARRAY_LIST_CAPACITY 50

struct List
{
    int limit;
    int num;
    int* entities;
};

//constructor
struct List* listConst()
{
    struct List* newList;
    newList = malloc(sizeof(struct List));
    newList->entities = malloc(ARRAY_LIST_CAPACITY*sizeof(int));
    newList->limit = ARRAY_LIST_CAPACITY;
    newList->num = 0;

    return newList;  
}

//destructor
void listDest(struct List* list)
{
	free(list->entities);
	free(list);
}

//to check if index is valid
int isValidIndex(int i, struct List* list)
{
	return (i>=0 && i<list->limit) ? 1 : 0;
	
}

//add item to list
int listAdd(struct List* list, int item)
{
	if(list->num<ARRAY_LIST_CAPACITY)
	{
		list->entities[list->num] = item;
		list->num+=1;
		return 1;
	}
	else
	{
		return 0;
	}
	
};

//read item at index into variable
int listRead(struct List* list, int index, int* entity)
{
	if(index > 0 && index < list->limit)
	{
		*entity = list->entities[index];
		return 1;
	}
	else
	{
		return 0;
	}
};


//remove item from list
int listRem(struct List* list, int index)
{
	if(isValidIndex(index,list))
	{
		int* newEntities;
		newEntities = malloc(sizeof(int) * ARRAY_LIST_CAPACITY);

		for(int i=0; i<list->num; i++)
		{
			if(i < index)
			{
				newEntities[i] = list->entities[i];
			};
			if(i>index)
			{
				newEntities[i-1] = list->entities[i];
			}
		}
		list->num--;
		list->entities = newEntities;
		return 1;
	}

	else
	{
		return 0;
	}
};

//returns list size
int listSize(struct List* list)
{
	return list->num;
}

//returns treu of list is empty or false of not
int listIsEmpty(struct List* list)
{
	return (list->num == 0) ? 1 : 0;
}


//searches through list for item and prints index of item or -1 if not found
int listSearch(struct List* list, int item)
{
	int returnVal = -1;
	for(int i=0; i<list->num; i++)
	{
		if(list->entities[i] == item)
		{
			returnVal = i;
		}
	}
	return returnVal;
}

//prints items in list
void printList(struct List* list)
{
	if(list->num>0)
	{
		printf("[");
		for(int i=0; i<sizeof(list->entities); i++)
		{
			printf("%d ",list->entities[i]);
		}
		printf("]\n");
	}
}
