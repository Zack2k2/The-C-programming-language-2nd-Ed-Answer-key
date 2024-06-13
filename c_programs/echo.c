#include <stdio.h>

int isin(char *s,char c);

int isin(char *s,char c){
    while(*s != '\0'){
        if(*s == c)
            return 1;
        *s++;
    }
    return 0;
}

int main(int argc, int *argv[]){
    while(argc-->1)
        printf("%d : %c\n",isin("x/+-",argv[argc][0]),argv[argc][0]);
}
