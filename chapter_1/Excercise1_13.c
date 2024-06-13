
#include <stdio.h>
#define TRUE  1
#define FALSE 0

#define LEN 30

int main(){
    int length, highest;
    int counts[LEN];
    int c;
    highest = 0;

    for(int i = 0; i < LEN; i++){
        counts[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
          if (length) {
            counts[length]++;
            if (highest < counts[length]) highest = counts[length];
            length = 0;
          }
        } else {
          length++;
        }
    }
    /*
    printf("Data:\n");
    for(int v = 0; v < LEN; v++){
        printf("%d\n",counts[v]);
    }*/
    // print histogram

    for(int i = highest; i >= 0; i-- ){
        putchar('\n');
        for(int j = 0; j < LEN; j++){
            if(counts[j] >= i){
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
    for(int v = 0; v < LEN; v++){
        printf("%3d",v);
    }
    putchar('\n');
}
