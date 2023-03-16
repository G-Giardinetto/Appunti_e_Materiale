#include<stdio.h>
#include"utils.h"
#include"item.h"

void inputArray(Item *arr,int n){ //serve per riempire l'array
	int i;

	for (i=0; i<n; i++)
		arr[i] = inputItem();
}

void outputArray(Item *arr,int n){  //serve per stampare l'array
	int i;
	for (i=0; i<n; i++)
	  outputItem(arr[i]);
}


void bubbleSort(Item *arr, int n){
  int i, j;
  for(i=1; i<n; i++)
    for(j=0; j < n-i; j++)
		if(cmpItem(arr[j], arr[j+1])>0)
      //if(arr[j] > arr[j+1])
			swap(&arr[j], &arr[j+1]);

  } //algortimo di ordinamento bubblesort
