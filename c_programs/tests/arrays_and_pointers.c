#include <stdio.h>

int main(){
	int a[10] = {12,4,75,31,54,13,5,46,17,13};
	int *int_p ;
	int_p = &a[0];
	for(int index = 0 ; index <= 9; index++) printf("Address[0x%x] contain [%d]\n",(int_p),*(int_p++));
}
