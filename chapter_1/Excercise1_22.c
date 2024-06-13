#include <stdio.h>
#define MAXLINE 10000


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

void fold(char s[], int n){
    int cur_pos = 0;

    while(s[cur_pos] != '\0'){
        if(cur_pos > 0 && cur_pos % n == 0){
            putchar(s[cur_pos]);
            putchar('\n');
        } else {
            putchar(s[cur_pos]);
        }
        cur_pos++;
    }
}

int main(){
    int len;
    char line[MAXLINE];
    while((len = get_line(line,MAXLINE )) > 0){
       fold(line,80); 
    }
    
    return 0;


}
