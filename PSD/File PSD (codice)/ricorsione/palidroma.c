#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalindromaIt(const char *s);

int isPalindromaTail(const char *s);

int isPalindromaTail1(const char *s,int i,int j);

int isPalindroma(const char *s);

int isPalindromaBrutta(const char *s,int l);

int main(int argc, char const *argv[])
{
    if(argc!=2)
    {
        fprintf(stderr,"Numero argomenti non esatto: riprovare\n");
        exit(EXIT_FAILURE);
    }

    

    if (isPalindroma(argv[1]))
        printf("palindroma\n");
    else
        printf("non palindroma\n");
    
    

    return 0;
}

int isPalindromaIt(const char *s){

    int i=0,j;
    j=strlen(s)-1;

    while (i<j){
        if (s[i]!=s[j])
            return 0;
        else
        {
            i++;
            j--;
        }
        
    }
    return 1;

}

int isPalindromaTail(const char *s){
    return isPalindromaTail1(s,0,strlen(s)-1);
}

int isPalindromaTail1(const char *s, int i,int j){
    if (i<j){
        if (s[i]!=s[j])
            return 0;
        else
        {
            isPalindromaTail1(s,i+1,j-1);
        }
        
    }
    return 1;
}

int isPalindroma(const char* s){

    return isPalindromaBrutta(s,strlen(s));
    
}

int isPalindromaBrutta(const char *s,int l){
    if (l<=1)
        return 1;
    else
        if (s[0]!=s[l-1])
            return 0;
        else
            isPalindromaBrutta(s+1,l-2);  
}
