#include <stdio.h>

int main(){
    int i = 0;
    int loop = 1;

    for (; loop ;){
        if (i <= 10){
            printf("%d\n",i);
            i++;
        } else {
            loop = 0;
        }
    }
}
