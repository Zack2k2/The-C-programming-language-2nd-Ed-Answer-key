#include <stdio.h>

int reverse(char original_string[],char reverse_string[]);
int reverse(char original_string[],char reverse_string[]){
         int i,j,len;
         len = j = 0;
          while(original_string[len]!='\0') len++;
          for(i=len-1,j=0;j<=len-1;i--,j++){
                  reverse_string[j] = original_string[i];
	  }
	
          reverse_string[j] = '\0';
 	  return len; 
}
int get_line(char s[],int lim);
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


int main(){
for(;;){
	char w_str[100];
	int len;
	char sc[100];
	
	len = get_line(sc,100);
	reverse(sc,w_str);
	printf(":[%s][%d]\n",w_str,len);

}
}
