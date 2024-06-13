#include <stdio.h>
#define MAXLINE 1000

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

/**
 * entab - replaces string of blanks by the minimum number of tabs and spaces.
 */
int entab(char line[], int tab_width){
    int i,j,k;
    int nt, nb;

    i = j = k = 0;
    nt = nb = 0;

    while(line[i] != '\0'){
        if (line[i] == ' '){
            if (i % tab_width != 0){
                nb++;
            } else {
                nt++;
                nb = 0;
            }
        }
        else {
            for( ; nt > 0; --nt){
                putchar('\t');
            }
            for( ; nb > 0; --nb){
                putchar(' ');
            }
            putchar(line[i]);
        }
        i++;
    }
    return i; 
}

int main(){
    int len;
    char line[MAXLINE];
    while((len = get_line(line,MAXLINE )) > 0){
        //trimWhitespace(line, len);
        entab(line, 8);
    }
    
    return 0;


}
