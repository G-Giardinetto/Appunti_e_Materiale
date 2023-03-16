#include <stdio.h>
#include "queue.h"
#include "item.h"
#define DIM 5

int main()
{

	int i;
	Item e;
	Queue coda = newQueue();

	for (i = 0; i < DIM; i++)
	{
		e = inputItem();
		enqueue(coda, e);
		printQueue(coda);
		printf("\n--\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	for (i = 0; i < 6; i++)
	{
		e = dequeue(coda);
		if (e != NULL)
		{
			printf("Elemento cancellato: ");
			outputItem(e);
		}
		printf("\n");
		printQueue(coda);
		printf("\n--\n");
	}

	return 0;
}
