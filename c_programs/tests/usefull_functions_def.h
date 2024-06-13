#include <stdio.h>

int pstrncmp(char *s,char *t,int n);
int pgetline(char *s,int limit);
void pstrncpy(char *to,char *from,int n);
int pstrlen(char *s);
void *ptr_strncat(char *s,char *ct,int n);


void *ptr_strncat(char *s,char *ct,int n){
        s += pstrlen(s);
        while((*s++ = *ct++)!='\0' && n-->0);
}

int pstrlen(char *s){
    char *p = s;
    while (*p != '\0') p++;
    return p-s;
}

void pstrncpy(char *to,char *from,int n){
    while ((*to++ = *from++) && n-->0 )
        ;
}

int pstrncmp(char *s,char *t,int n){
    for (; *s == *t && n-->0;*s++,*t++) if(*s=='\0') return 0;
    return *s-*t;
}

int pgetline(char *s,int lim)
{
    int c;

    int i;
    for(i=0;(c=getchar())!= EOF && c != '\n' && lim > i; ++i) *(s+i) = c;
    if (c == '\n')
        *(s+i) = c;
        i++;
    *(s+i) = '\0';
    return i;
}
