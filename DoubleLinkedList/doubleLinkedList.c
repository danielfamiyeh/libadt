#include <stdlib.h>
#include <stdio.h>

struct DoubleList
{
    int size;
    struct ListNode* head;
    struct ListNode* tail;
};

struct ListNode
{
    int data;
    struct ListNode* next;
    struct ListNode* prev;
    
};

struct ListNode* nodeConst(int val)
{
    struct ListNode* node;
    node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->data = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
};

void nodeDest(struct ListNode* node)
{
    free(node);
}

struct DoubleList* doubleListConst()
{
    struct DoubleList* list;
    list = (struct DoubleList*)malloc(sizeof(struct DoubleList));
    
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void doubleListDest(struct DoubleList* list)
{
    struct ListNode* temp;
    struct ListNode* current = list->head;
    while(current)
    {
        temp = current;
        current = current->next;
        free(temp);   
    }
}


// Append to end of list
int doubleListAdd(struct DoubleList* list, int entity)
{
    struct ListNode* node = nodeConst(entity);
    if(node != NULL)
    {
        if(list->size == 0)
        {
            list->head = node;
            list->tail = node;
        }

        if(list->size > 0)
        {
            node->prev = list->tail;
            list->tail->next = node;
            list->tail = node;
        }

        list->size++;
        return 1;
    }
    else
    {
        printf("Error - Could not alloate memory for node.\n");
        return 0;
    }
    
};

int doubleListAddFront(struct DoubleList* list, int entity)
{
    struct ListNode* node = nodeConst(entity);
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
            list->head->prev = node;
            list->head = node;
        }

        return 1;
        
    }
    else
    {
        printf("Error - Could not allocate memory for node.\\n");
        return 0;
    }
    
}

int doubleListRem(struct DoubleList* list, int index)
{
    if(list->size > 0)
    {
        if(index >= 0 && index < list->size)
        {
            struct ListNode* temp;
            if(index == 0 || index == (list->size-1))
            {
                if(index == 0)
                {
                    temp = list->head;
                    list->head = temp->next;
                    list->head->prev = NULL;
                    nodeDest(temp);
                }

                else if(index == (list->size-1))
                {
                    temp = list->tail;
                    list->tail = temp->prev;
                    list->tail->next = NULL;
                    nodeDest(temp);
                }
            }

            else
            {
                int count = 0;
                temp = list->head;
                struct ListNode* temp2;
                while(count < index)
                {
                    if(count == index-1)
                    {
                        temp2 = temp->next;
                        temp->next = temp2->next;
                        temp2->next->prev = temp;
                        nodeDest(temp2);
                    }
                    count++;
                }
            }

            list->size--;

        }
        else
        {
            printf("Error - Index out of range.\n");
        }
        
    }
    else
    {
        printf("Error - List is empty.\n");
    }
    
};

void doubleListPrint(struct DoubleList* list)
{
    int count = 0;
    struct ListNode* current = list->head;
    while(current)
    {
        printf("Index: %d\nItem: %d\n\n", count, current->data);
        current = current->next;
        count++;
    }
}

int doubleListSearch(struct DoubleList* list, int val)
{
    int index = -1;
    if(list->size > 0)
    {
        int count = 0;
        struct ListNode* current = list->head;
        while(current)
        {
            if(current->data == val)
            {
                index = count;
            }
            current = current->next;
            count++;
        }
    }
    else
    {
        printf("Error - List is empty.\n");
    }
    
    return index;
}

int doubleListGetSize(struct DoubleList* list)
{
    return list->size;
}

int doubleListIsEmpty(struct DoubleList* list)
{
    return (list->size == 0) ? 1 : 0;
}
