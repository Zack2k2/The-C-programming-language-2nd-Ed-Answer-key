/*
The following program prints the last then lines from input:

*/

#include <stdio.h>

#define MAX_LINES 100

void writelines(char *lines[],int start,int stop);
int ptr_getline(char *line,int limit);
int getlines(char *lines[],int limit);

// This function recives a line from input and loads it in to '*line'
// line must be no longer then limit
// NOTE: This fuction also counts newline character '\n'
int ptr_getline(char *line,int limit){
    int string_length=0;
    int c;
    int i;
    // keep reciving input characters until a newline is encountered
    // or an end of file is encountered and make sure that string length
    // is smaller then limit
    for (i=0;(c=getchar())!=EOF && c != '\n' && i < limit-1;++i) {
        *(line+i) = c;
    }
    if (c == '\n') {
        *(line+i) = c;
        i++;
    }
    *(line+i) = '\0';
    return i;
}

int getlines

int main(int argc, char const *argv[]) {
    char line[200];
    int len;
    len = ptr_getline(line,200);
    printf("%s\n",line);
    printf("%d\n",len);
    return 0;
}
