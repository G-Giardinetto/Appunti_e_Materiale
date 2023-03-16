#include <stdio.h>
#include "array.h"
#include "item.h"
#define N 100

int main(){

	Item arr[N];
	int n=5;

	inputArray(arr, n);
	bubbleSort(arr, n);
	outputArray(arr, n);

	return 0;
}
