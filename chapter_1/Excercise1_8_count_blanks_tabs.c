#include <stdio.h>

int main(){
    long nb, nn, nt, nc;
    int c;
    nc = nb = nn = nt = 0;

    while((c=getchar())!= EOF){
        if(c == ' ') nb++;
        else if (c == '\n') nn++;
        else if (c == '\t') nt++;
        else nc++;
    }

    printf("blanks %ld\nnewlines %ld\ntabs %ld\ncharacters %ld\n",nb,nn,nt,nc);

}
