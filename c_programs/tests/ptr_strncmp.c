#include <stdio.h>
#include <string.h>
#include "some_usefull_functions.h"

int ptr_strncmp(char *s,char *t,int n);
int ptr_strncmp(char *s,char *t,int n){
    for (; *s == *t && n-->0;*s++,*t++) if(*s=='\0') return 0;
    return (*s-'0')-(*t-'0');
}

void main(){
    char s1[50];
    char s2[50];
	printf("Enter a first line:\n");
    get_line(s1,50);
    printf("Enter a second line:\n");
    get_line(s2,50);
    printf("%d\n",strncmp(s1,s2,5));
}
