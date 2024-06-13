#include <stdio.h>
#define MAXLINE 1000

void copy(char to[], char from[]){
    int i;

    i = 0;

    while((to[i] = from[i]) != '\0') ++i;
}

int get_line(char s[], int lim){
    int c, i;
    for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        ++i;
    }
    s[i] = '\0';
    return i;
    
}

void reverse(char s[]){
    int len;
    len = 0;
    char tmp[MAXLINE];
    copy(tmp,s);
    //printf("%s",tmp);
    int i, j, k;
    i = j = k = 0;
    for(i = 0; s[i] != '\0'; i++)
        ;
    
    for(k = (i-1); k >= 0; k--){
        putchar(s[k]);
    }
    putchar('\n');
}

int main(){

    int len;
    char line[MAXLINE];
    while((len = get_line(line,MAXLINE )) > 0){
        reverse(line);
    }
    
    return 0;

}

