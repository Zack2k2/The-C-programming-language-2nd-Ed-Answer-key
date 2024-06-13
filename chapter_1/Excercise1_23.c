#include <stdio.h>
#define MAXLINE 5000
#define FALSE   0
#define TRUE    1


// global declearing 
int is_first_fs             = FALSE;
int is_star_after_fs        = FALSE;
int is_fs_after_start       = FALSE;
int in_one_line_comment     = FALSE;
int in_multiline_comment    = FALSE;


/**
 * get a line and loads it into s
 * kflsdfsdllkls
 * kfalsasfklaskasfasfkasf
 * lksfalflaslasfafjkffffffffffa
 *
 * kkfllaf;kaslaskasf
 */
int get_line(char s[], int lim){
    int c, i;
    for(i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i/*lol*/] = '\0';
    return i;
    
}
// Hello
// test
void putline(char line[], int len){  // my name is zack
    int index = 0;

    while((line[index] != '\0' && line[index] != '\n') && index < len){
        if(line[index] == '/'){
            if(line[index+1] == '/'){
                break;
            } else if(line[index+1] == '*'){
                in_multiline_comment = TRUE;
            } else if(line[index-1] == '*' && in_multiline_comment){
                line[index] = ' ';  /* Delete the forward slash*/
                in_multiline_comment = FALSE;
            }
        }
        if (!in_multiline_comment /* && index < len*/){
            printf("%c",line[index]);
        }
        index++;
    }

}

// hello world
int main(/*int argc, char *argv[]*/){

    int len;
    char line[MAXLINE];

    /*
     * This is such a nice 
     * comment, i hope this gets deleted 
     * in the final output 
     * */


    while((len = get_line(line,MAXLINE )) > 0){
    
        putline(line,MAXLINE);
        putchar('\n');
    }
    
    return 0;

}

