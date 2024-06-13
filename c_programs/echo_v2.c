#include <stdio.h>
void main(int argc, char const *argv[]){for(int i=1;i<argc;i++) printf("%s%s",argv[i],(i==argc-1)? "\n" : " " );}
