

#include <stdio.h>
#include <string.h>
#define MAX_LEN 500

int getline_v1(char *str,int max);

int getlines_v1(char lineptr[MAX_LEN][MAX_LEN], int maxlines);

void writelines(char lines[MAX_LEN][MAX_LEN], int nlines);

int main(int argc, char *argv[]){
    char strs[MAX_LEN][MAX_LEN];
    int nlinesfounds;

    nlinesfounds = getlines_v1(strs,MAX_LEN);
    printf("%d\n",nlinesfounds);
    writelines(strs,nlinesfounds);
    return 0; 
}

void writelines(char lines[MAX_LEN][MAX_LEN], int nlines){
    int index = 0;
    for(index = 0; index < nlines; index++){
        printf("%s\n",lines[index]);
    }

}


int getline_v1(char *str, int max){
    int i,c;
    i = 0;

    while(--max > 0 && ((c = getchar()) != EOF && c != '\n'))
    {
        str[i++] = c;
    }
    if (c == '\n'){
        str[i++] = c;
    }
    str[i] = '\0';
    return i;
}

int getlines_v1(char linesptr[MAX_LEN][MAX_LEN], int maxlines){
    
    char line[MAX_LEN];
    int index = 0;
    int len;
    while((len=getline_v1(line,MAX_LEN)) > 0){
        if(len >= maxlines)
        {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(linesptr[index++],line);
            printf("%s\n",line);    
        }
    }

    return index;    
}

void quicksort(char *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

}


void swap
