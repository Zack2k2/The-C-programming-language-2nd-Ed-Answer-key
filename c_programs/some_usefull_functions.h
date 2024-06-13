#define MAX_LENGTH 65535 // that is 2^16 -1
#include <string.h>
#include <stdio.h>
#include <math.h>

// returns  the lowercharater of corresponding uppercharater c
int lower(int c);

/*
 *recives input from STDIN in string 's' until a newline is encountered;
 *returns the number of charaters revived
 *prescribed within the limits of 'lim'
 */
int get_line(char s[],int lim);

// reverses/flips/mirrors the string in argument string 's'
// note:funtion does not preserve the old string
void reverse(char s[]);

/*
 * reverse_ko : reverse keep original
 * reverse the string 'original_string' in to 'reverse_string'
 * keeping 'original_string' untouched
*/
void reverse_ko(char original_string[],char reversed_string[]);

//same as strcpy() from <string.h>
void copy(char to[],char from[]);

//same as strcat() from <string.h>
void str_cat(char s[],char t[]);

/*
 * returns the decimal equivalent of the number in hexadacimal given in argument hex_string[]
 * keeps the hex_string untouched
 */
int _htoi_(char hex_string[]);

/*
 * converts the the decimal number 'n' in to the number of number system of base 'b'
 * returning the result in the string s[]
*/
int itob(int n,char s[],int b);

//returns the index of first occurance of character c in string s1
int anyc(char s1[],int c);

// 
int any(char s1[],char s2[]);

void escape(char s[],char t[]);

const char* byte_to_binary(int x);

unsigned int invert(unsigned x , int p , int n);

unsigned int getbits(unsigned x , int p , int n);

unsigned int setbits(unsigned x,int p,int n,unsigned y);

unsigned rightroc(unsigned x, int n);

int bitcount(unsigned x);

#include "usefull_funtions_def.h"
