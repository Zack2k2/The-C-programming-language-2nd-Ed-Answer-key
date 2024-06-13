#include <stdio.h>
#define MAXLINE 5000
#define MAXCHARS 10000
#define FALSE 0
#define TRUE  1

int get_str(char str[], int limit){
    int i, c;
    i = 0;

    while(i < limit - 1 && (c = getchar()) != EOF){
        str[i++] = c;
    }
    str[i] = c;

    return i;
}

int main(){

    int len;
    char prog_str[MAXCHARS];
    int index;

    int parentheses, brackets, braces;
    int single_quotes = FALSE;
    int double_quotes = FALSE;
    int block_comment = FALSE;
    parentheses = brackets = braces = 0; 
    
    len = get_str(prog_str, MAXCHARS);

    index = 0;

    while(index < len){
        if (prog_str[index] == '('){
            parentheses++;
        } else if (prog_str[index] == ')'){
            parentheses--;
        } else if (prog_str[index] == '['){
            brackets++;
        } else if (prog_str[index] == ']'){
            brackets--;
        } else if (prog_str[index] == '{'){
            braces++;
        }else if (prog_str[index] == '}'){
            braces--;
        }else if (prog_str[index] == '/'){
            if (prog_str[index+1] == '*'){
                block_comment = TRUE;
            } else if (prog_str[index-1] == '*'){
                if(block_comment == TRUE) {
                    block_comment = FALSE;
                } else {
                    block_comment = TRUE;
                }
            } 

        } else if (prog_str[index] == '\''){
            if (single_quotes == FALSE){
                parentheses = TRUE;
            } else {
                parentheses = FALSE;
            }
        } else if (prog_str[index] == '\"'){
            if (double_quotes == FALSE){
                double_quotes = TRUE;
            } else {
                double_quotes = FALSE;
            }
        }


        index++;
    }

    if (parentheses != 0){
        printf("[ERROR] unbalanced parentheses ()\n");
    }
    if (brackets != 0){
        printf("[ERROR] unbalanced brackets []\n");
    } 
    if (braces != 0){
        printf("[ERROR] unbalanced braces {}\n");
    }
    if (block_comment == TRUE){
        printf("[ERROR] unbalanced block comments\n");
    }
    if (single_quotes == TRUE){
        printf("[ERROR] unbalanced single quotes\n");
    }

    if (double_quotes == TRUE){
        printf("[ERROR] unbalanced double quotes\n");
    } 
    return 0;

}
