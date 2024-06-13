#include "some_usefull_functions.h"
#include <stdio.h>
#include <ctype.h>

void expand(char s1[],char s2[]);

void expand_digits(int start,int end,char s[]); // expand digits from start to end

void expand(char s1[],char s2[]){
  int i=0;
  while(s1[i] != '\0'){
    if(s1[i] == '-' && isdigit(s1[i+1])){

    }
    i++;
  }

}
