#include <stdio.h>
#include "some_usefull_functions.h"

void escape(char s[],char t[]);

void escape(char s[], char t[]){
  char c;
  int i,j;
  for(i=0,j=0;(c=t[i])!='\0';i++,j++){
    switch(c){
      case '\t':
        s[j]   = '\\';
        s[++j] = 't';
        break;
      case '\n':
        s[j]   = '\\';
        s[++j] = 'n';
        break;
      default:
        s[j]   =  c;
        break;
    }

  }
  s[j] = '\0';
}
void main(){
  char s1[512];
  char s2[512];
  printf("enter a string: \n");
  get_line(s1,511);
  escape(s2,s1);
  printf("%s\n",s2);
}
