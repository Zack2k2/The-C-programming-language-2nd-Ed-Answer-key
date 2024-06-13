#include <stdio.h>
#include <string.h>
#include "learning_c.h"
void padded_itoa(long long int n , char s[] ,int p);
void padded_itoa(long long int n,char s[],int p){
  short is_neg;
  int padding_index;
  if(n < 0){
    is_neg = 1;
    n = n * -1;
  }
  int i;
  i=0;
  do{
      s[i++] = n % 10 + '0';
      p--;
  }while(((n/=10)>0) && p > 0);
  if(is_neg == 1) s[i++] = '-';
  s[i] = '\0';
  for(padding_index = 1 ; padding_index < p ; padding_index++ ) strcat(s," ");
  reverse(s);


}
int main(){
    char dec_string[20];
    int number = 57871;
    padded_itoa(number,dec_string,18);
    printf("%s\n",dec_string);
}
