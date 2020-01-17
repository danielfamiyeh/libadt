//Doubly-linked list queue implementation

#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int val;
    struct Node* next;
    struct Node* prev;
};

struct QueueList
{
    int length;
    struct Node* head;
    struct Node* tail;
};

struct Node* nodeConst(int val)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void nodeDest(struct Node* node)
{
    free(node);
}

struct QueueList* queueListConst()
{
    struct QueueList* queue = (struct QueueList*)malloc(sizeof(struct QueueList));
    queue->length = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

void queueListDest(struct QueueList* queue)
{
    struct Node* temp;
    struct Node* current = queue->head;
    while(current)
    {
        temp = current;
        current = temp->next;
        free(temp);
    }
}

int queueListAdd(struct QueueList* queue, int entity)
{
    struct Node* node = nodeConst(entity);

    if(node != NULL)
    {
        if(queue->length == 0)
        {
            queue->head = node;
            queue->tail = node;
        }
        else
        {
            queue->tail->next = node;
            node->prev = queue->tail;
            queue->tail = node;
        }
        queue->length++;
        return 1;
    }
    else
    {
        return 0;
    }   
}

int queueListRem(struct QueueList* queue)
{
    int data;
    if(queue->length > 1)
    {
        struct Node* head = queue->head;
        data = head->val;
        struct Node* afterHead = queue->head->next;
        nodeDest(head);
        afterHead->prev = NULL;
        queue->head = afterHead;
        return data;
    }
    else if(queue->length == 1)
    {
        data = queue->head->val;
        nodeDest(queue->head);
        queue->head = NULL;
        queue->tail = NULL;
        return data;
    }
    else
    {
        printf("Error - List is empty.\n");
    }
}

void queueListPrint(struct QueueList* queue)
{
    int count = 0;
    struct Node* current = queue->head;

    while(current)
    {
        printf("Index: %d\nValue: %d\n\n", count, current->val);
        current = current->next;
        count++;
    }
}

int queueListPeek(struct QueueList* queue)
{
    return queue->head->val;
}