#include <stdio.h>
#include "learning_c.h"
#define MAXLINE 1000
int main(){
  char line[MAXLINE];
  int found =0;
  while(get_line(line,MAXLINE)) > 0)
    if(str_index(line,"is") > 0)
      printf("%s\n",line);
      found++;
  return found;
}
