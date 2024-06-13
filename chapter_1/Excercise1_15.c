#include <stdio.h>

int fahr_to_cel(int f){
    return  (5 * (f - 32) / 9);
}

int main(){
    int fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper ){
        printf("%d\t%d\n", fahr, fahr_to_cel(fahr));
        fahr = fahr + step;
    }
}
