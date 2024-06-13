#include <stdio.h>
#include <string.h>
#include "some_usefull_functions.h"

unsigned int invert(unsigned x , int p , int n);

unsigned int invert(unsigned x , int p , int n){
  int right_most_bits = 0;
  int left_most_bits  = 0;
  int i_bits          = 0;  //i_bits  is inverted bits
  i_bits              =  (~0 & ~(getbits(x,p,n)));
  right_most_bits     = getbits(x,p-n,p-n+1);
  left_most_bits      = getbits(x,(sizeof(x)*8)-1,(sizeof(x)*8)-p-1);

  i_bits = i_bits << (p - n + 1);
  left_most_bits = left_most_bits << (p + 1);

  int result=0;
  result = left_most_bits | i_bits | right_most_bits ;

  return result;
}

int main(){
    invert(175,4,3);

    invert(187,6,4);


}
