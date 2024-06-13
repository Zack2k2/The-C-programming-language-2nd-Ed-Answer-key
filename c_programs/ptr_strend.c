#include <stdio.h>
#include "some_usefull_functions.h"

//int strend(char *str,char c);
int ptr_strlen(char *str);
int ptr_strlen(char *str)
{
	char *p = &str[0];
	
	while(*p != '\0')
		p++;
	return p - str;

}
//int strend(char *str,char c){

//}

int main(void){
	printf("Enter a line:\n");
	char *s1;
	get_line(s1,50);
	printf("the length is %s\n",s1);

}
