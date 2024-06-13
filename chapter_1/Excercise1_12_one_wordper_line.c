#include <stdio.h>

int main(){
    int c;
    while((c=getchar()) != EOF){
       if(c == ' ' || c == '\t' || c == '\n' || c == '\v'){
           putchar('\n');
       } else {
           putchar(c);
       }
    }
}
