#include <stdio.h>
#include "pointer_string.h" 

void swap(char *str, int x, int y){
    char temp;
    temp = *(str + x);
    *(str + x) = *(str + y);
    *(str + y) = temp;
}

int main(){
    char greetings1[] = "Hello, World";
    char greetings2[] = "I want to become a great hacker.";
    char line[512];
    /*
    swap(greetings1,2,6);

    printf("%s\n",greetings1);

    swap(greetings2,4,10);
    printf("%s\n",greetings2);

    */
    homemadegetline(line,100);
    printf("%s",line);
}
