#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fibonacciIter(int n);
int fibonacci(int n);

int main(int argc, char *argv[])
{
  int n;
  clock_t start,end;
  double tempo;
  if(argc!=2)
  {
    fprintf(stderr,"Numero argomenti non esatto: riprovare\n");
    exit(EXIT_FAILURE);
  }
  n=atoi(argv[1]);
  start=clock();
  printf("Il numero di Fibonacci e':%d\n",fibonacci(n));
  end=clock();
  tempo=((double)(end-start));
  printf("Tempo impiegato:%f\n",tempo);
  system ("pause");
  return 0;
}

int fibonacci(int n)
{
  if(n==0 || n==1)
    return 1;
  else
    return fibonacci(n-1)+fibonacci(n-2);
}

int fibonacciIter(int n)
{
  int i,prev1=1,prev2=1,f=1;
  for(i=2;i<=n;i++)
  {
    f=prev1+prev2;
    prev1=prev2;
    prev2=f;
  }
  return f;
}
