#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char const *argv[]) {
  char c;
  int count=0;
  int fdin=open(argv[1], O_RDONLY);
  while(read(fdin,&c,1))
    if(c== 'a'|| c== 'e'||
       c=='i' || c=='o' ||
       c=='u' || c=='y'   ) count++;
   printf("%d\n", count);
  return 0;
}
