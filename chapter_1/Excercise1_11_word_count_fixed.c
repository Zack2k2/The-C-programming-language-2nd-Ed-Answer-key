#include <stdio.h>
#define IN  1
#define OUT 0
/**
 * What type of input could reveal any bugs?
 * Ans) vertical tab '\v'
 * # echo "hello world\nmy name is zack\vi love programming\tEid mubarak Everyone\v\v\v\v <3\vlol\vgetme" | ./a.out
      2      15      85
 * # echo "hello world\nmy name is zack\vi love programming\tEid mubarak Everyone\v\v\v\v <3\vlol\vgetme" | wc  
      2      15      85
 */

int main(){
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while((c=getchar()) != EOF){
        ++nc;
        if(c == '\n'){
            ++nl;
        } 
        if (c == ' ' || c == '\n' || c == '\t' || c == '\v'){
            state = OUT;
        } else if ( state == OUT){
            state = IN;
            nw++;
        }
    }
    printf("\t%d\t%d\t%d\n", nl, nw, nc);
}


