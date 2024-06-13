#include <stdio.h>

void diamond(int height);
int getint(void);

int getint(void){
	int index;
	int num=0;
	int c;
	for(index=1;(c=getchar())!= EOF && c != '\n' && (c<='9' && c>='0') ;index++){
		num = num + (c-'0')*index;
	}
	return num;
}

void diamond(int height){
	int x,y,mid;
	for(y=0;y<=height;y++){
		for(x=0;x<=height;x++){
			mid = (height-1)/2;
			if(x== mid || (x<=y+mid && x>=mid-y && y<=mid) || ( y>=mid && x<= (height-1)-(y-mid) ) && x>=y-mid ) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

int main(void){
	int h;
	printf("Enter the height of the diamond:\n");
	h = getint();
	diamond(h);

}
