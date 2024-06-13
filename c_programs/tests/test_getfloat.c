#include <stdio.h>
#include "learning_c.h"

int get_float(float *pn);

int get_float(float *pn){
  int c,sign;

  while(isspace(c = getchar())) /*skip all white spaces*/
    ;
  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){   /*cheak if the character is a number or a sign if not*/
    ungetch(c);                                          /* then push char to input and return zero*/
    return 0;
  }
  sign = (c == '-') ? -1:1;
  if(c == '+' || c =='-') c = getchar(); //if a character is a sign then get a number
  if(!isdigit(c)){
    ungetch(c);
    return 0;
  }

  *pn = 0.0;
  while(isdigit(c)){
    *pn = 10.0 * *pn + (c-'0');
    c = getchar();
  }

  int power = 1;
  if (c == '.'){
    int power = 1;
  }
  while (isdigit(c=getchar())){
      power = power * 10 ;
      *pn = 10.0 * *pn + (c-'0');
  }
  *pn = *pn / power;


  *pn *= sign;
  if (c != EOF) ungetch(c);
  return c;
}

int main() {
  float f=0;
  int status;

  status = get_float(&f);
  printf("%lf\n",f);
  return 0;
}
