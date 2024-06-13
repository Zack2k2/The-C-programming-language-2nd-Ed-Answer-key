#include <stdio.h>

#define TRUE 1
#define FALSE 0

int pstrcat(char *s,char *t){

    while(*s++ != '\0')
        ;
 
    s--; // discard the null character.
    while((*s++ = *t++)!='\0')
        ;

    return TRUE;
}

int main(){

    char intro[50] = "hello world my name is plank";
    pstrcat(intro," , I am a programmer");

    printf("%s\n",intro);
}
