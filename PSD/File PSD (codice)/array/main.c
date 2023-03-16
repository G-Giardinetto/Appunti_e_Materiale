#include <stdio.h>
#include "array.h"
#define N 10

int main(){

	int arr[N], n, element, valore;
	printf("Quanti elementi vuoi inserire? ");
	scanf("%d", &n);
	inputArray(arr, n);

	printf("Inserisci elemento da ricercare: ");
	scanf("%d", &element);
	valore = ricercaBinariaRec(arr, n, element);
	if(valore<0)
		printf("\nElemento non trovato!\n");
	else
		printf("Elemento trovato in posizione %d\n", valore);

		return 0;
}
