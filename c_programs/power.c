#include <stdio.h>
#include "learning_c.h"
#include <math.h>
int main(){
	int i;
	for(i=0;i<16;i++){
		printf("num[%d] 2^num[%lld]\n",i,power(2,i));
	}
}
