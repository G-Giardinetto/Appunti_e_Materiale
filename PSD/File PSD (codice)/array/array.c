#include <stdio.h>
#include "utils.h"

void insertSortedArray(int *array, int *size, int element)
{
	int i;
	for(i=*size;i>0;i--)
		if(element < array[i-1])
			array[i] = array[i-1];
		else
			break;

	array[i] = element;
	*size += 1;
	//(*size)++;
}

void insertionSort(int *array, int size)
{
	int i;
	for(i=1;i<size;)
		insertSortedArray(array, &i, array[i]);
}
void inputArray(int *arr,int n){
	int i;

	for (i=0; i<n; i++)
		scanf(" %d",&arr[i]);
}

void outputArray(int *arr,int n){
	int i;
	for (i=0; i<n; i++)
		printf("%d ",arr[i]);
    printf("\n");
}

int minimo(int *arr,int n){
	int min = 0;
	int i;
	for (i = 1; i<n; i++)
		if (arr[i] < arr[min])
			min = i;

	return min;
}

void selectionSort(int *arr,int n){
	int i,min;
	for (i = 0; i<n-1; i++){

		min = minimo(arr+i,n-i)+i;
		//swap(arr+i,arr+min);
		swap(&arr[i],&arr[min]);

	}
}

void bubbleSort(int *arr,int n){
    int i,j;
    for (i=1;i<n;i++)
      for (j=0;j<n-i;j++)
        if(arr[j]>arr[j+1])
          swap(&arr[j],&arr[j+1]);

}
int adaptiveBubbleSort(int *arr,int n){
    int i,j,ordinato=0,contatore=0;
    for (i=1;i<n && !ordinato;i++){
      ordinato=1;
      for (j=0;j<n-i;j++){
        contatore++;
        if(arr[j]>arr[j+1]){
          ordinato=0;
          swap(&arr[j],&arr[j+1]);
        }
      }
    }
    return contatore;

}

int ricercaBin(int *arr, int n, int element){
	int inizio = 0, fine = n-1, centro;

	while(fine >= inizio){
		centro=(inizio+fine)/2;
		if(element == arr[centro])
			return centro;
		else if(element < arr[centro])
			fine = centro - 1;
		else if(element > arr[centro])
			inizio = centro + 1;
	}
	return -1;
}

int ricercaord(int *arr, int n, int element){
	int i = 0;
	while(i< n &&  arr[i] < element)
		i++;
	
	return (i<n && arr[i]==element? i: -1);
}

//T(n) = T(n/2)+c
int ricercaBinariaRec1(int *arr, int inizio, int fine, int k){
	int centro;
	if(inizio > fine)
		return -1;
	else{
		centro = (inizio + fine)/2;
		if(k == arr[centro])
			return centro;
		else if(k > arr[centro])
			return ricercaBinariaRec1(arr, centro+1, fine, k);
		else
			return ricercaBinariaRec1(arr, inizio, centro-1, k);
	}
}

int ricercaBinariaRec(int *arr, int size, int k){
	return ricercaBinariaRec1(arr, 0, size-1, k);
}
