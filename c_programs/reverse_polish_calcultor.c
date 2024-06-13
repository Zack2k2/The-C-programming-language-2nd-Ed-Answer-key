#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'
#define MAX_STACK 1000

double val[MAX_STACK];
int sp=0;

int getop(char []);
void push(double);
double pop(void);

main(){
  int type;
  double op2;
  char s[MAXOP];

  while((type = getop(s))!= EOF){
    switch(type){
      case NUMBER:
        push(atof(s));
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop()-op2);
        break;
      case '/':
        op2 = pop();
        push(pop() / op2);
        break;
      case '\n':
          printf("\t:%.8f\t",pop());
          break;
      default:
            printf("error: unkown command %s\n",s);
            break;
    }
  }
  return 0;
}

void push(double x) {
  if(sp >= MAX_STACK) printf("Warning! The stack is full \n");
  else{
    val[sp] = x;
    sp++;
  }
}
double pop(void){
  if (sp <= 0){
    printf("Error: The stack is Empty\n");
    return 0.0;
  }else{
    return val[--sp];
  }
}
int getop(char s[]){
  int c;
  while((c = getch()) == ' ' || c == '\t')
    ;
  s[0] = c;
  s[1] = '\n';
  if(!isdigit(c) && c != '.') return c;
  i=0;
  if(isdigit(c)){
     while(isdigit(s[++i] = c = getch()))
      ;
  }
  if(c == '.') {
    while (isdigit((s[++i] = c = getch())))
      ;
  }
  s[i] = '\0';
  if(c != EOF){
    ungetch(c);
  }
  return NUMBER;
}
