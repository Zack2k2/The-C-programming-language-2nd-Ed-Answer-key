#include <stdio.h>


void itoa(int n, char s[]);

void itoa(int n,char s[]){
  int i,sign;
  if((sign = n) < 0){
    n = -n;
  }
  i=0;
  do{
    s[i++] = n % 10 -'0';
  }while((n/=10) > 0);
  if(sign < 0){
    s[i++] = '-';
    s[i]   = '\0';
  }
}
void main(){
  long long int i;
  char s[10];
  for(i = -1500;i != 0;i++){
    itoa(i,s);
    printf("[DEC:%lld]:[STR:%s]\n",i,s);
    if(i % 100 == 0) getchar();

  }

}
