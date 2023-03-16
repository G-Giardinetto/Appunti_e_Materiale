
#include <stdio.h>
#include <stdlib.h>


int MCDit(int a,int b);
int MCD(int a,int b);

int main(int argc, char const *argv[])
{

    int a,b;
    if(argc!=3)
    {
        fprintf(stderr,"Numero argomenti non esatto: riprovare\n");
        exit(EXIT_FAILURE);
    }

    a=atoi(argv[1]);
    b=atoi(argv[2]);

    printf("MCD:%d\n",MCD(a,b));
    return 0;
}

int MCDit(int a,int b){
    int r;
    while (b!=0)
    {
        r = a%b;
        a=b;
        b=r;
    }

    return a;
    
}

int MCD(int a,int b){
    if (b==0)
        return a;
    else
        return MCD(b,a%b);
}
