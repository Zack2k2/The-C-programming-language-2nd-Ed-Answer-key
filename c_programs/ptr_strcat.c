#include <stdio.h>
#include "some_usefull_functions.h"
void ptrstrcat(char *s,char *t);
void remove_nl(char *s);

void ptrstrcat(char *s ,char *t){
	while(*s != '\0') *s++;
	while(*s++ = *t++) 
		;
}
void remove_nl(char *s){
	char c;
	while(*s++ != '\0'){
		c = *s;
		if(c != '\n')
			*s = c;
		
	}
}
int main(void){
	char s1[40];
	char s2[20];
	printf("Enter first string\n:");
	get_line(s1,39);
	//remove_nl(s1);
	//strcpy(s1,"hello world");
	
	printf("now enter another string\n:");
	get_line(s2,19);
	
	ptrstrcat(s1," This str is meant to be appended");
	printf("the combined string is [%s]\n",s1);

	
}
