#include <stdio.h>
#include <string.h>
#include "some_usefull_functions.h"

#define MAX_LINES 100

// these variables are declared as static because..
// ..they have to retain there value after each operation
static char allocbuff[MAX_LENGTH];
static char *allocp = &allocbuff[0]; // could also be written as static char *allocp = allocbuff

char *alloc(int n);  // allocate n bytes from stack(i.e array alloc buff) ; returns a pointer to the beganning from the memory portion
void afree(char *p);         // frees a portion of memory portion

// This function get a line
int ptr_getline(char *s,int lim);   // similar funtion to getline()
void writelines(char *lines[],int nlines); // writes lines
int pstrcmp(char *s1,char *s2);
void swap(char *v[],int i,int j);
void qsort(void *lineptr[],int left, int right, int (*comp)(void *,void*));


int ptr_getline(char *s,int lim){
    char c;
    int string_length = 0;
    // no intail statement for for loop is required be cause we are using pointer airthmetic
    for(;(c=getchar())!='\n';string_length++,s++){
        if (c == EOF){
            *s = '\0';
            return string_length;
        }
        else{
            *s = c;
        }
    }
    if(c == '\n'){
        *s = c;
        s++;
        string_length++;
    }
    *s = '\0';
    return string_length;
}

char *alloc(int n)
{
    if(allocbuff + MAX_LENGTH - allocp >= n)
    /*
     * for me the above condition was bit hard to understand
     * basically it checks if a stack have enought storage
     * for starters when no memory allocated then the address in allocbuff and allocp are equal
     * (i.e) allocbuff - allocp = 0  , 0 + MAX_LENGTH = MAX_LENGTH ? MAX_LENGTH >= n then allocate space
     * when alloc() have been called onece or several time the memory allocated , let it be 's'
     * allocbuff - s < 0 ; MAX_LENGTH + (allocbuff -s) would give the free memory we have
     */
    {
        allocp += n;   // moves the allocp forward by n bytes
        return allocp-n; // return the pointer pointing to beginning of the allocated block of memory
    }
    else{ // if no space is avaliable return NULL
        return NULL;
    }
}
void afree(char *p){
    //
    if(p >= allocbuff && p < allocbuff + MAX_LENGTH) allocp = p;
}

int readlines(char *lineptr[],int maxlines){
    char line[MAX_LINES];
    int len;
    int nlines=0;
    while((len=ptr_getline(line,MAX_LENGTH))>0){
        if(nlines >= maxlines /*|| p == NULL*/ ){
            return -1;
        } else{
            line[len-1] = '\0'; //removes '\n' from end of line
            allocp += len;
            char *p = (char *)(allocp - len + 1 );
            strcpy(p,line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

void writelines(char *lines[],int nlines){
    while(nlines-->0)
        printf("%s\n",*lines++);
}

int pstrcmp(char *s1,char *s2){
    for(;*s1 == *s2;*s1++,*s2++)
        return 0;
    return *s1 - *s2;
}


void qsort(char *v[],int left,int right){
    int i,last;
    void swap(char *v[],int i,int j);

    if(left >= right) return ;
    swap(v,left,(left + right)/2);
    last = left;
    for(i = left +1; i <= right;i++)
        if(pstrcmp(v[i],v[left]) < 0)
            swap(v,++last,i);

    swap(v,left,last);
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}

void swap(char *v[],int i ,int j){
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


int main() {
    char *lineptr[MAX_LINES];
    int nlines;
    if((nlines = readlines(lineptr,MAX_LINES)) >= 0){
        qsort(lineptr,0,nlines-1);
        writelines(lineptr,nlines);
        return 0;
    } else {
        printf("%s\n","error: input too big to sort");
        return 1;
    }
}
