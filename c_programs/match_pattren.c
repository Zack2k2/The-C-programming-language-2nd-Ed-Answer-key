#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int ptr_getline(char *s,int lim);   // similar funtion to getline()
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
int main(int argc, char const *argv[]) {
    char line[MAXLINE];
    int found = 0 ;
    if (argc != 2) printf("%s\n","Usage: find pattern");
    else
        while(ptr_getline(line,MAXLINE)>0)
            if(strstr(line,argv[1]) != NULL){
                printf("%s",line);
                found++;
            }
    return found;
}
