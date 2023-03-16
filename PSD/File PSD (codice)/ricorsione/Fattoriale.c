//Fattoriale

#include <stdio.h>
#include <stdlib.h>

int fattorialeIter(int n);
int fattoriale(int n);

int main(int argc, char *argv[])
{
  int n;
  if(argc!=2)
  {
    fprintf(stderr,"Numero argomenti non esatto: riprovare\n");
    exit(EXIT_FAILURE);
  }
  n=atoi(argv[1]);
  printf("Il fattoriale del valore inserito e':%d\n",fattoriale(n));
  system ("pause");
  return 0;
}

int fattorialeIter(int n)
{
  int f=1,i;
  for(i=2;i<=n;i++)
      f=f*i;
  return f;
}

int fattoriale(int n)
{
  if(n<=1)
    return 1;
  else
    return n*fattoriale(n-1);
}
