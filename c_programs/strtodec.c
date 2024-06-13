#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

long double strtodec(char *s);

long double strtodec(char *s){
	int i,len;
	long long int p;
	len = strlen(s);
	int frac=0;
	long double num=0.0;
	int ndigit=0;
	for(i=0;i<=len;i++){
		if(s[i] >= '0' && s[i] <= '9'){
			ndigit++;
			p = pow(10,len-ndigit);
			num = num + ((s[i]-'0') * p);
		} else if(s[i] == '.'){
			frac = len  - ndigit;
			//frac = len - i;
		}
	}
	return num/pow(10,frac);
}

int main(int argc,char *argv[]){
	if(argc < 2){
		printf("%s <string>\n",argv[0]);
		exit(1);
	}
	printf("%Lf\n",strtodec(argv[1]));
}
