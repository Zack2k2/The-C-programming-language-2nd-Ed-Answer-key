#include <stdio.h>
// #include <string.h>
#include "usefull_functions_def.h"

int ptr_strncmp(char *s,char *t,int n);
int ptr_strncmp(char *s,char *t,int n){
    for (; *s == *t && n-->0;*s++,*t++) if(*s=='\0') return 0;
    return *s-*t;
}

void main(){
    char s1[20];
    char s2[20];
	printf("Enter a first line:\n");
    pgetline(s1,50);
    printf("Enter a second line:\n");
    pgetline(s2,50);
    printf("%d\n",ptr_strncmp(s1,s2,20));
}
