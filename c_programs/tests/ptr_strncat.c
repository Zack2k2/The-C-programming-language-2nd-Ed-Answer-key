#include <stdio.h>
#include <string.h>
#include "some_usefull_functions.h"


// concatonates 'n' numbers of 'ct' at ends of 's'
void *ptr_strncat(char *s,char *ct,int n);

void *ptr_strncat(char *s,char *ct,int n){
        s += strlen(s);
        while((*s++ = *ct++)!='\0' && n-->0);
}

void main(){
    char s1[50];
    char s2[50];
	printf("Enter a first line:\n");
    get_line(s1,50);
    printf("Enter a second line:\n");
    get_line(s2,50);
    ptr_strncat(s1,s2,strlen(s2));
    printf("%s\n",s1);


}
