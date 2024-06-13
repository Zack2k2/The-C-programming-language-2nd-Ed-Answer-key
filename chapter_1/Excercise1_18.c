#define MAXLINE 1000
#include <stdio.h>

/**
 * Removes white spaces from start and end of the string.
 */
void trimWhitespace(char *str, int length) {
    int start = 0, end;

    // Find the index of the first non-space character from the start
    while (str[start] == ' '){
        start++;
    }

    // Find the index of the last non-space character from the end
    end = length;
    while (end > start && str[end] == ' '){
        end--;
    }

    // Shift the non-space part of the string to the beginning
    int i;
    for (i = start; i <= end; i++){
        str[i - start] = str[i];
    }

    // Null-terminate the string at the end position
    str[i - start] = '\0';
}


int get_line(char s[], int lim){
    int c, i;

    for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main(){
    int len;
    char line[MAXLINE];
    while((len = get_line(line,MAXLINE )) > 0){
        trimWhitespace(line, len);
        printf("%s",line);
    }
    
    return 0;


}
