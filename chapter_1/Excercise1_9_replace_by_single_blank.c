#include <stdio.h>
#define IN 1
#define OUT 0
int main(){
    
    int c;
    int bstate = IN;
    while((c=getchar()) != EOF)
    {
       if(c == ' ') 
       {
            bstate = OUT;
       } else if( bstate == OUT /*&& c != ' '*/) {
            bstate = IN;
            putchar(' ')
                ;
            putchar(c);
       } else {
            putchar(c);
        
       }
    }
    return 0;
}
