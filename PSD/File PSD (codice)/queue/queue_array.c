#include <stdlib.h>
#include "item.h"
#include "queue.h"

// To-do: Cambiare dopo il testing
// Fix: MAXQUEUE 50

#define MAXQUEUE 50

struct queue
{
    Item elements[MAXQUEUE];
    int head, tail;
};

Queue newQueue()
{
    Queue coda = malloc(sizeof(struct queue));
    coda->head = 0;
    coda->tail = 0;

    return coda;
}

int isEmptyQueue(Queue coda)
{
    return (coda->head == coda->tail);
}

int enqueue(Queue coda, Item e)
{
    if ((coda->tail + 1) % MAXQUEUE == coda->head)
        return 0;

    coda->elements[coda->tail] = e;
    coda->tail = (coda->tail + 1) % MAXQUEUE;

    return 1;
}

Item dequeue(Queue coda)
{
    if (isEmptyQueue(coda))
        return NULL;

    Item ret = coda->elements[coda->head];
    coda->head = (coda->head + 1) % MAXQUEUE;

    return ret;
}

void printQueue(Queue coda)
{
    int i;

    for (i = coda->head; i != coda->tail; i = (i + 1) % MAXQUEUE)
        outputItem(coda->elements[i]);
}