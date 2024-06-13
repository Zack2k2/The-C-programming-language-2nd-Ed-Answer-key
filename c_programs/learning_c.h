#include <stdio.h>
#include <string.h>
#include <ctype.h>

void reverse(char s[]);
int get_line(char s[],int lim);
unsigned int getbits(unsigned x,  int p, int n);
unsigned int setbits(unsigned x , int p , int n ,unsigned y);
const char* byte_to_binary(int x);
void str_cat(char s[],char t[]);
int kreverse(char original_string[],char reversed_string[]);
int get_line(char s[],int lim);
void copy(char to[],char from[]);
int getint(int *pn);
//int getfloat(int *pn);



#define BUFSIZE 100
int getch(void);
void ungetch(int val);
char buf[BUFSIZE];
int  bufp = 0;

int getch(void)
{
  return (buf > 0) ? buf[--bufp] : getchar();
}
void ungetch(int val)
{
  if (bufp >= BUFSIZE) printf("Warning! The buffer is full\n");
  else buf[bufp++] = val;
}

int getint(int *pn)
{
  int c,sign;

  while(isspace(c = getch())) /*skip all white spaces*/
    ;
  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    ungetch(c);
    return 0;
  }
  sign = (c = '-') ? -1:1;
  if(c == '+' || c =='-') c = getch();
  if(!isdigit(c)){
    ungetch(c);
    return 0;
  }

  *pn = 0;
  while(isdigit(c = getch()))
    *pn = 10 * *pn + (c-'0');

  *pn *= sign;
  if (c != EOF) ungetch(c);
  return c;
}
/*
int getfloat(float *pn){
  int c,sign;

  while(isspace(c = getch())) /*skip all white spaces*//*
    ;
  if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
    ungetch(c);
    return 0;
  }
  sign = (c = '-') ? -1:1;
  if(c == '+' || c =='-') c = getch();
  if(!isdigit(c)){
    ungetch(c);
    return 0;
  }

  *pn = 0;
  while(isdigit(c = getch()))
    *pn = 10 * *pn + (c-'0');

  power = 0
  if (c == '.')
    int power = 0;
  while (isdigit(c=getch())){
      power++;
      *pn = 10 * *pn +(c - '0');
  }
  *pn = *pn / power;

  *pn = *sign;
  if (c != EOF) ungetch(c);
  return c;
}*/


void reverse(char s[]){
  int i,j;
  char key;

  for(i=0,j=strlen(s)-1;i != strlen(s) && j>0;i++,j--){
    key = s[i];
    s[i] = s[j];
    s[i] = key;
  }
}
unsigned int getbits(unsigned x,  int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}
unsigned int setbits(unsigned x , int p , int n ,unsigned y){
	int y_tmp,set_bits;
	y_tmp = set_bits = 0;
	set_bits = getbits(x,p,n);
	y_tmp    = getbits(y,(sizeof(y)*8)-1,(sizeof(y)*8)-n);
	y_tmp    = y_tmp << n;
	return y_tmp | set_bits;
}

const char* byte_to_binary(int x){
	static char b[9];
	b[0] = '\0';
	int z;
	for(z=128;z>0;z>>=1)
	{
		str_cat(b,((x & z) == z) ? "1" : "0");

	}
	return b;

}

void str_cat(char s[],char t[]){
	int i,j;
	i = j = 0;
	while(s[i] != '\0') i++;
	while((s[i++] = t[j++]) != '\0')
		;
}


int kreverse(char original_string[],char reversed_string[]){
         int i,j,len;
         len = j = 0;
          while(original_string[len]!='\0') len++;
          for(i=len-1,j=0;j<=len-1;i--,j++){
                  reversed_string[j] = original_string[i];
          }

          reversed_string[j] = '\0';
          return len;
}


int get_line(char s[],int lim){
        int c,i ;

        for(i=0;(c=getchar())!= '\n';++i){
                if(i >= lim -1)   return 0;
                else if(c == EOF)
                {
                        s[i] = '\0';
                        return i;
                }
                else {
                        s[i]=c;
                }

        }
        if(c == '\n'){
                s[i] = c;
                i++;
        }
        s[i]='\0';
        return i;
}

void copy(char to[],char from[]){
        int i=0;
        while((to[i]=from[i])!='\n') ++i;
        //return i;
}
