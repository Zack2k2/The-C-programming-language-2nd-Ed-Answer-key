#include <stdio.h>
#include "some_usefull_functions.h"
int main(){
  int p=0;
  char line[50];
  copy(line,"a clever ");
  p = anyc(line,'c'-0);
  printf("%d:%c\n",p,line[p]);
  p = any(line,"zxkv");
  printf("%d:%c\n",p,line[p]);
}
