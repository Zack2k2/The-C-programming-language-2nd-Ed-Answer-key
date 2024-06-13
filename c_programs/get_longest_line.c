#include <stdio.h>
#define MAX_LIM 120

int get_line(char s[],int lim);
void copy(char to[],char from[]);

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

int main(){
	int len,max;
	char working_string[MAX_LIM];
	char longest_string[MAX_LIM];
	max = 0;	

	while((len = get_line(working_string,MAX_LIM))>0){
		if(len > max){
			copy(longest_string,working_string);
			max = len;
		
		}	
	}
	printf("the longest string is [%s] of length[%d]\n",longest_string,max);

}
