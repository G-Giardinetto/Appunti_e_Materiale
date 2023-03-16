#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "key.h"
#define MAX 20

int equals(Key k1, Key k2)
{
	char *s1=k1,*s2=k2;
	if(strcmp(s1,s2)==0)
		return 1;
	return 0;
}

int hashValue(Key k, int m)
{ 
	int h = 0;
	char *v=k;
	int a = 128;
	for (; *v != '\0'; v++) 
		h = (h*a + *v) % m;
	return h;
}

Key inputKey()
{
	char *a=malloc(sizeof(char)*MAX);
	scanf("%s",a);
	return a;
}

void outputKey(Key k)
{
	char *stringa=k;
	printf("%s\n",stringa);

}