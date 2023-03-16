#include <stdio.h>
#include "utils.h"

void insertSortedArray(int *array, int *size, int element)
{
	int i;
	for (i = *size; i > 0; i--)
		if (element < array[i - 1])
			array[i] = array[i - 1];
		else
			break;

	array[i] = element;
	*size += 1;
	//(*size)++;
}

void insertionSort(int *array, int size)
{
	int i;
	for (i = 1; i < size;)
		insertSortedArray(array, &i, array[i]);
}
void inputArray(int *arr, int n)
{
	int i;

	for (i = 0; i < n; i++)
		scanf(" %d", &arr[i]);
}

void outputArray(int *arr, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int minimo(int *arr, int n)
{
	int min = 0;
	int i;
	for (i = 1; i < n; i++)
		if (arr[i] < arr[min])
			min = i;

	return min;
}

void selectionSort(int *arr, int n)
{
	int i, min;
	for (i = 0; i < n - 1; i++)
	{

		min = minimo(arr + i, n - i) + i;
		// swap(arr+i,arr+min);
		swap(&arr[i], &arr[min]);
	}
}

void bubbleSort(int *arr, int n)
{
	int i, j;
	for (i = 1; i < n; i++)
		for (j = 0; j < n - i; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}
int adaptiveBubbleSort(int *arr, int n)
{
	int i, j, ordinato = 0, contatore = 0;
	for (i = 1; i < n && !ordinato; i++)
	{
		ordinato = 1;
		for (j = 0; j < n - i; j++)
		{
			contatore++;
			if (arr[j] > arr[j + 1])
			{
				ordinato = 0;
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
	return contatore;
}

int ricercaBin(int *arr, int n, int element)
{
	int inizio = 0, fine = n - 1, centro;

	while (fine >= inizio)
	{
		centro = (inizio + fine) / 2;
		if (element == arr[centro])
			return centro;
		else if (element < arr[centro])
			fine = centro - 1;
		else if (element > arr[centro])
			inizio = centro + 1;
	}
	return -1;
}

int ricercaord(int *arr, int n, int element)
{
	int i = 0;
	while (i < n && arr[i] < element)
		i++;

	return (i < n && arr[i] == element ? i : -1);
}

void merge(int *a1, int *a2, int n1, int n2, int *a)
{

	int i = 0, j = 0, k = 0;
	int b[n1 + n2];

	for (; i < n1 && j < n2; k++)
	{
		if (a1[i] <= a2[j])
		{
			b[k] = a1[i];
			i++;
		}
		else
		{
			b[k] = a2[j];
			j++;
		}
	}

	for (; i < n1; i++, k++)
		b[k] = a1[i];

	for (; j < n2; j++, k++)
		b[k] = a2[j];

	for (k = 0; k < n1 + n2; k++)
		a[k] = b[k];
}

void mergeSort(int *arr, int n)
{

	if (n > 1)
	{
		mergeSort(arr, n / 2);
		mergeSort(arr + n / 2, n - n / 2);
		merge(arr, arr + n / 2, n / 2, n - n / 2, arr);
	}
}

int partition(int *arr, int start, int end)
{
	int pivot = arr[start];
	int i = start - 1, j = end + 1;

	while (1)
	{
		do
		{
			j--;
		} while (arr[j] > pivot);

		do
		{
			i++;
		} while (arr[i] < pivot);

		if (i >= j)
			return j;

		swap(arr + j, arr + i);
	}
}

void qSort(int *arr, int start, int end);

void quickSort(int *arr, int size)
{

	qSort(arr, 0, size - 1);
}

void qSort(int *arr, int start, int end)
{
	// caso base
	//  start>=end

	if (start < end)
	{
		int q = partition(arr, start, end);
		qSort(arr, start, q);
		qSort(arr, q + 1, end);
	}
}