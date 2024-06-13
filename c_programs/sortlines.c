#include <stdio.h>
#define MAXLIINES 100

void pstrcmp(char *s1,char *s2);
void swap(char *v[],int i,int j);
void writelines(char *v[],int nlines);
int pgetline(char *lineptr[],int lim);
void qsort(char *v[],int left, int right);
int readlines(char *lineptr,int maxlines);




int main(int argc, char const *argv[]) {
    char *lineptr[MAXLIINES];
    int nlines = 0;
    while(pgetline(lineptr[nlines],100) > 0) nlines++;
    qsort(lineptr,0,nlines-1);
    writelines(lineptr,nlines);
    return 0;
}

int pgetline(char *lineptr,int lim){
    int c;
    int n=0
    for(n;(c=getchar())!= EOF && c != '\n' && n <(lim-1) ;++n) *(lineptr+n) = c;
    if (c == '\n')
        *(lineptr+n) = c;
        n++
    *(lineptr+n) = '\0';
    return n;
}

int pstrcmp(char *s1,char *s2){
    for(;*s1 == *s2;*s1++,*s2++) return 0;
    return *s1 - *s2;
}

int readlines(char *lineptr[],int lim){
    int nlines=0;
    int len;
    while((len=pgetline(lineptr+nlines) > 0 && nlines < lim)){
        *(lineptr[len] + nlines) = '\0';
        nlines++;
    }
}

void swap(char *v[],int i ,int j){
    char *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
void qsort(char *v[],int left,int right){
    int i,last;
    void swap(char *v[],int i,int j);

    if(left >= right) return ;
    swap(v,left,(left + right)/2);
    last = left;
    for (i = left +1; i <= right;i++)
        if (pstrcmp(v[i],v[left]) < 0)
            swap(v,++last,i);
    swap(v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}


void writelines(char *lineptr[],int nlines) {
    while (nlines-->0) printf("%s\n",lineptr++);
}
