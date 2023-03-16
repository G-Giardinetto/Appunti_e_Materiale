#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int i=0;
  while (i<15) {
    printf("%d\n", rand());
    i++;
  }
  return 0;
}
