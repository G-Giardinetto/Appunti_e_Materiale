#include <stdlib.h>
#include "item.h"
#include "queue.h"
#include "list.h"

struct queue
{
    List elements;
};

Queue newQueue()
{
    Queue coda = malloc(sizeof(struct queue));
    coda->elements = newList();

    return coda;
}

int isEmptyQueue(Queue coda)
{
    return isEmpty(coda->elements);
}

int enqueue(Queue coda, Item e)
{
    return addListTail(coda->elements, e);
}

Item dequeue(Queue coda)
{
    return removeHead(coda->elements);
}

void printQueue(Queue coda)
{
    printList(coda->elements);
}