#include "some_usefull_functions.h"
#include <stdio.h>

int main(){
  char text[30];
  copy(text,"A CLEVER BROWN FOX");
  int i;
  for (i=0;i<10;i++){
    printf("%c\n",lower(text[i]-0));
  }
}
