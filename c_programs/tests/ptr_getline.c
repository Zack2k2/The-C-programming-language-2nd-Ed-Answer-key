#include <stdio.h>
#include "usefull_functions_def.h"

int ptr_getline(char s[],int lim);

int ptr_getline(char *s,int lim){
    int c;
    int i;
    for(i=0;(c=getchar())!= EOF && c != '\n' && lim > i; ++i) *(s+i) = c;
    if (c == '\n')
        *(s+i) = c;
        i++;
    *(s+i) = '\0';
    return i;
}
int  main(int argc, char const *argv[]) {
    const char *s1;
    s1 = input("Enter a string: ");
    printf("%s\n",s1 );
    return 0;
}
