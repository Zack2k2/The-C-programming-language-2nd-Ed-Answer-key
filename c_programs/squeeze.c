#include <stdio.h>
#include "some_usefull_functions.h"

void squeeze(char s[], int c);
void squeeze2(char s1[], char s2[]);

void squeeze(char s[], int c)
{
	//printf("%s\n",);
	int i, j;
	i = j = 0;
	while(s[i] != '\0'){
		if (s[i] != c)
		{	
			s[j++] = s[i];
		}
		i++;
	}
	s[j] = '\0';
}

void squeeze2(char s1[],char s2[]){
	int k;
	
	for(k=0;s2[k] != '\0';k++){
		squeeze(s1,s2[k]);
		
	}
	
	//printf("%s\n",s1);
}

/* ok so here goes the main funtion don't screw this up zohaib
 * oh i just learned that you could make prety commrents with vim
 */

int main(){
	char working_line[MAX_LIM];
	char deleting_chars_line[MAX_LIM];
	printf("Please enter the line to be edited\n");
	get_line(working_line,MAX_LIM);
	printf("Please enter the characters to be edited\n");
	get_line(deleting_chars_line,MAX_LIM);
	squeeze2(working_line,deleting_chars_line);
	printf("%s\n",working_line);
	return 0;
}


