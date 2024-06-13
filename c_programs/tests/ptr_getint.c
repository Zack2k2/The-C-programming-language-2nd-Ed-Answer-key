
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

double getfloat(char *s);

double getfloat(char *s){
    int length,div_power_offset;

    double x=0.0;
    int is_float = FALSE;
    int sign=1;
    int i = 0;

    length = strlen(s);
    div_power_offset = 0;

    while (s[i] == ' ') i++;  // skip all white spaces
    length -= i;
    if (s[i]=='-'){
        sign = -1;
        length--;
        i++;
     }
    while(i<length){
        if(s[i] >= '0' && s[i] <= '9' && s[i] != '.') x += (s[i]-'0') * pow(10,(length-1-i));
        else if (s[i] ==' ') i++; //ignore white spaces
        else if ((s[i]=='.') && (is_float==FALSE)){
            is_float == TRUE;
            div_power_offset = length-i;
            length++;
        }
        else i++; //for other characters
        i++;
    }
    return (x/pow(10,div_power_offset)*sign);
}
int main(int argc,char *argv[]){
  char s[15];
  if (argc < 2){
      printf("%s {number}\n",argv[0]);
      exit(1);
  }
  printf("%lf\n",getfloat(argv[1]));
}
