#include <stdio.h>
#include <string.h>
#include "some_usefull_functions.h"

//int strend(char *str,char c);
int ptr_strlen(char *str);
int ptr_strlen(char *str)
{
	char *p =str;

	while(*p != '\0')
		p++;
	return p - str;

}
int ptr_strend_v1(char *s,char *t){ // returns 0 if string s ends with t
	char *ot = t;     // saves the intial position of 't' in 'ot'
	t += (strlen(t)); // moves the pointer at the end of a string 't'
	s += (strlen(s)); // moves the pointer at the end of a string 's'
	while(*s-- == *t--){
		if(*s != *t && t != *ot){
			return (*s-'0') - (*t -'0');
		}
	}
	return 0;
	//return (*s-'0') - (*t -'0');
}
// returns
int ptr_strend_v2(char *s,char *t){
	s += (strlen(s) - strlen(t) ); // moves the pointer of 's' to a position where the number to characters
	  							 // left is equal to the number of characters of t
	while(*s++ == *t++ && *s != '\0') // compere the rest of characters from 's' and 't' until a difference is found ...
	 								  // ... or the string 's' has ended
		; // 'an empty body' because due to nature of while it requires a requires a body
	return (*s-'0') - (*t-'0'); // return difference between two characters if these two cha
}

int main(void){
	char s1[50];
	char s2[50];

/*	printf("Enter a first line:\n");
	get_line(s1,50);
	printf("Enter a second line:\n");
	get_line(s2,50);
*/
	strcpy(s1,"inertia is a property of matter");
	strcpy(s2,"property of matter");
	printf("[%d]\n",ptr_strend_v1(s1,s2));
	printf("[%d]\n",ptr_strend_v2(s1,s2));

}
