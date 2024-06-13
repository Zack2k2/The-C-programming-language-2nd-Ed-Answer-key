long long int power(int n,int b){
  int i;
  long long int num = 1;
  for(i=0;i < b; i++)
    num = num * n;
  return num;
}

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

void itoa(long long int n,char s[]){
  int i;
  long long int sign;
  if((sign = n) < 0){
    n = -n;
  }
  i=0;
  do{
    s[i++] = n % 10 +'0';
  }while((n/=10) > 0);
  if(sign < 0){
    s[i++] = '-';
  }
  s[i]   = '\0';
  reverse(s);
}
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
unsigned rightroc(unsigned x, int n)
{
    while (n-- > 0)
        if(x & 1)
            x = (x >> 1) | ~(~0U >> 1);
        else
            x = x >> 1;
    return x;
}


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
		strcat(b,((x & z) == z) ? "1" : "0");

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

void reverse(char s[]) {
    int c,i,j;
    for(i=0,j=strlen(s)-1;j>i;i++,j--){
      c=s[i];
      s[i]=s[j];
      s[j]=c;
    }
}

void reverse_ko(char original_string[],char reverse_string[]){
         int i,j,len;
         len = j = 0;
          while(original_string[len]!='\0') len++;
          for(i=len-1,j=0;j<=len-1;i--,j++)
                  reverse_string[j] = original_string[i];

          reverse_string[j] = '\0';
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
}

int anyc(char s1[],int c){
    int i;
    for(i=0;s1[i] != '\0';i++) if(s1[i] == c) return i;
    return -1;

}

int _htoi_(char hex_string[]){
	char rev_hex_string[MAX_LENGTH];
	int length,i,j;
	int dec,c;
	length = j = dec = 0;
	while(hex_string[length] != '\0') length++; //again equivalent to: length = strlen(hex_string);

	for(i=length-1;i>=0;i--,j++){
		if(hex_string[j] >= 'A' && hex_string[j] <= 'F') c = hex_string[j] - 55;        //<-- only works for ascii
		else if(hex_string[j] >= 'a' && hex_string[j] <= 'f') c = hex_string[j] - 87;	//<--   Only works for ascii
		else{
			c= hex_string[j] - '0';
		}
		dec += power(16,i) * c;

	}
	return dec;
}

int itob(int n,char s[],int b){
  int sign,i;
  if((sign = n) < 0) n = n * -1;

  i = 0;
  if(b <= 2 ) return -1;
  else if (b <= 10){
      do{
        s[i++] = n%b +'0';
      }while((n/=b) > 0);
  }else{
      int c;
      do{
        c = n % b;
        if(c >= 10) s[i++] = c + ('a' - '\n') ; // need to implement corresponding_alpha(char c) function
        else s[i++] = c + '0';
      }while((n/=b)>0);
  }
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
  return 0;
}

int any(char s1[],char s2[]){
  int i,j;
  for(j=0;s2[j]!='\0';j++) for(i=0;s1[i] != '\0';i++) if(s1[i] == s2[j]) return i;
  return -1;
}

int bitcount(unsigned x){
  int b;
  for(b=0;x != 0; x &= (x-1)) b++;
  return b;

}

int lower(int c){
   return (c >= 'A' && c <= 'Z') ? (c + 'a'-'A') : c;
}
