#include <stdio.h>
#include <math.h>
#define MAX_LENGTH 32

//Funtions prototypes


int get_one_line(char string[]);
int reverse(char original_string[],char reverse_string[]);
int _htoi_(char hex_string[]);
int lower(int c);

//funtions definations

int get_one_line(char string[]){
	int i,c;

	for(i=0;(c=getchar())!='\n';i++){
		//if(c == '\n') string[i] = '\0';
		 string[i] = c;
	}
	string[i] = '\0';
	printf("%s\n",string);
	return i;
}

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
		dec += pow(16,i) * c;

	}
	return dec;
}
int lower(int c){
	if(c >= 'A' && 'Z' => c) return c + 'a' - 'A';
	return c;

}
int main(){
	 char working_string[MAX_LENGTH];
	 int convert_numbers;
	 int num;
	 printf("Enter the number in hex:\n");
 	 get_one_line(working_string);

	 convert_numbers = _htoi_(working_string);
	 if(convert_numbers==-1){
	 	printf("opps some thing went wronge with checking!!\n");
	 	return 0;
	 } else if (convert_numbers == -2) {
	 	printf("some thing went wrong with numbers\n");
		return 0;
	 }

	 printf("dec:%d\n",convert_numbers);

}
