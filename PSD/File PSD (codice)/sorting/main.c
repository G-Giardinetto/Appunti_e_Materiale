#include <stdio.h>
#include "array.h"
#define N 5

int main()
{

    int ad[N];

    inputArray(ad, N);

    quickSort(ad, N);

    outputArray(ad, N);

    return 0;
}
