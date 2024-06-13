#include <stdio.h>
#include <string.h>
const char* byte_to_binary(int x);
unsigned int getbits(unsigned x , int p , int n);
unsigned int setbits(unsigned x,int p,int n,unsigned y);



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

int main(){

	int i,j;
	unsigned int k;
	k = 179;
	for(i=255;i>0;i--){
		j=setbits(i,5,4,k);
		printf("for number 179 when place at right most bits \n of %s bits at position 3 and bits grabed was  %d:\n",byte_to_binary(i),j);

	}
}
