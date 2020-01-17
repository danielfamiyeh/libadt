#include <stdlib.h>
#include <stdio.h>

struct ListNode
{
    int data;
    struct ListNode* next;
};

struct SingleList
{
    int size;
    struct ListNode* head;
    struct ListNode* tail;
};


struct ListNode* listNodeConst(int val)
{
    struct ListNode* node;
    node = (struct ListNode* )malloc(sizeof(struct ListNode));
    node->data = val;
    node->next = NULL;
}

void listNodeDest(struct ListNode* node)
{
    free(node);
}

struct SingleList* singleListConst()
{
    struct SingleList* list;
    list = (struct SingleList*)malloc(sizeof(struct SingleList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

int singleListAdd(struct SingleList* list, int entity)
{
    struct ListNode* node;
    node = listNodeConst(entity);

    if(node != NULL)
    {
        if(list->size == 0)
        {
            list->head = node;
            list->tail = node;
        }
        else
        {
            list->tail->next = node;
        }

        list->size++;
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int singleListAddFront(struct SingleList* list, int entity)
{
    struct ListNode* node;
    node = listNodeConst(entity);

    if(node != NULL)
    {
        if(list->size == 0)
        {
            list->head = node;
            list->tail = node;
        }

        else
        {
            node->next = list->head;
            list->head = node;
        }
        list->size++;
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int singleListRead(struct SingleList* list, int index, int* varPtr)
{
    int count = 0;
    struct ListNode* current = list->head;
    while(current)
    {
        if(count == index)
        {
            *varPtr = current->data;
        }
        count++;
        current = current->next;
    }
    
}

int singleListGetSize(struct SingleList* list)
{
    return list->size;
}

int singleListIsEmpty(struct SingleList* list)
{
    return (list->size == 0) ? 1 : 0;
}

void singleListPrint(struct SingleList* list)
{
    if(list->size > 0)
    {
        struct ListNode* current = list->head;
        int index = 0;
        while(current)
        {
            printf("Index: %d\nItem: %d\n\n", index, current->data);
            current = current->next;
            index++;
        }
    }
}

void singleListDest(struct SingleList* list)
{
    struct ListNode* current = list->head;
    struct ListNode* temp;
    while(current)
    {
        temp = current;
        current = current->next;
        listNodeDest(temp);
    }
    free(list);
}

int singleListRem(struct SingleList* list, int index)
{
    if(list->size > 0 && index >= 0 && index <= list->size)
    {
        struct ListNode* current = list->head;
        if(list->size == 1)
        {
            free(current);
            list->head = NULL;
            list->tail = NULL;

            list->size--;
            return 1;
        }
        else
        {
            int count = 0;
            struct ListNode* temp;
            while(count <= index-1)
            {
                current = current->next;
                if(count == index-1)
                {
                    temp = current->next;
                    current->next = current->next->next;
                    listNodeDest(temp);
                }
                count++;
            }
            list->size--;
            return 1;
        }
        
    }

    else
    {
        return 0;
    }
}