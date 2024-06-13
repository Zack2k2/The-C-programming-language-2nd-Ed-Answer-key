#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX 31
#define NUM_ALPHA 26

int main(){
    int curr_length, lower_highest, upper_highest;
    int lower[NUM_ALPHA];
    int upper[NUM_ALPHA];

    int c;

    for(int _ = 0; _ < NUM_ALPHA; _++){
        lower[_] = 0;
        upper[_] = 0;
    }
    lower_highest = upper_highest = 0;
    while((c=getchar()) != EOF ){
        if (c >= 'a' && c <= 'z'){
            lower[c-'a']++;
            if(lower[c-'a'] > lower_highest ){
                lower_highest = lower[c-'a'];
            }

        } else if ( c >= 'A' && c <= 'Z'){
            upper[c-'A']++;
            if(upper[c-'A'] > upper_highest){
                upper_highest = upper[c-'A'];
            }
        }
    }

    //printf("[DEBUG]lower high: %d\n",lower_highest);
    //printf("[DEBUG]upper high: %d\n",upper_highest);
    //printf("[DEBUG]Data:\n");
    /*for(int v = 0; v < NUM_ALPHA; v++){
        printf("%d\n",lower[v]);
    }
    printf("===\n");
    for(int v = 0; v < NUM_ALPHA; v++){
        printf("%d\n",upper[v]);
    }*/
    // print histogram for lower characters
    printf("lower character histogram:\n");
    for(int i = lower_highest; i >= 0; i-- ){
        putchar('\n');
        for(int j = 0; j < NUM_ALPHA; j++){
            if(lower[j] >= i){
                if(i) printf("  #");
                else printf("  =");
            } else {
                putchar(' ');
                putchar(' ');
                putchar(' ');
            }
        }
    }
    putchar('\n');
    for(int v = 0; v < NUM_ALPHA; v++){
        printf("%3c",v+'a');
    }
    putchar('\n');
    putchar('\n');
    // print histogram for lower characters
    printf("upper character histogram:\n");
    for(int i = upper_highest; i >= 0; i-- ){
        putchar('\n');
        for(int j = 0; j < NUM_ALPHA; j++){
            if(upper[j] >= i){
                if(i) printf("  #");
                else printf("  =");
            } else {
                putchar(' ');
                putchar(' ');
                putchar(' ');
            }
        }
    }
    putchar('\n');
    for(int v = 0; v < NUM_ALPHA; v++){
        printf("%3c",v+'A');
    }
    putchar('\n');
}
