#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int ptr_getline(char *s,int lim);
int ptr_getline(char *s,int lim){
    char c;
    int string_length = 0;
    // no intail statement for for loop is required be cause we are using pointer airthmetic
    for(;(c=getchar())!='\n' && c != EOF;string_length++,s++){
        if (c == EOF){
            *s = '\0';
            return string_length;
        }
        else{
            *s = c;
        }
    }
    if(c == '\n' && string_length == 0){
        return 0;
    } else if (c == '\n'){
        *s = c;
        s++;
        string_length++;
    }
    *s = '\0';
    return string_length;
}

int main(int argc, char const *argv[]) {
    char line[MAXLINE];
    int c,found=0,except=0,number=0,lineno=0;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = *++argv[0]) {
            switch (c) {
                case 'x':
                case 'X':
                    except = 1;
                    break;
                case 'N':
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("Find: illegal option %c\n",c);
                    argc = 0;
                    found = -1 ;
                    break;
            }
        }
    }
    if (argc != 1) printf("%s\n","Usage: find -x -n pattern" );
    else{
        while (ptr_getline(line,MAXLINE) > 0){
            lineno++;
            if ((strstr(line,*argv) != NULL) != except){
                if(number) printf("%d:",lineno);
            }
            printf("%s\n",line);
            found++;
        }
    }
    return found;
}
