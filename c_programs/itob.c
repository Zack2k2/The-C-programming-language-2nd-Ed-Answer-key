#include "some_usefull_functions.h"
#include <stdio.h>

int main(void){
  char converted_string[20];
  int num;
  printf("Enter a number in decimal:");
  scanf("%d\n",&num);
  if((itob(num,converted_string,16)) == 0){
      printf("\n%s\n",converted_string);
  }

}
