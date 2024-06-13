#include <stdio.h>
#include <string.h>

void ptr_strncpy(char *to,char *from,int n); // copies 'n' from string 'from' to string 'to'

void ptr_strncpy(char *to,char *from,int n){
    while((*to++ = *from++)!='\0' && n-->0);
}

int
main(){
    char s1[50];
    char s2[50];

/*
    printf("Enter a first line:\n");
    get_line(s1,50);
    printf("Enter a second line:\n");
    get_line(s2,50);
*/
//    strcpy(s1,"inertia is a property of matter");
    ptr_strncpy(s2,"property of matter",strlen("property"));
    printf("%s\n",s2 );
}
