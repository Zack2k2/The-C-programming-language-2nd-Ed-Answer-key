#include <stdio.h>
#include <string.h>
#define MAXCHARS 10000
#define MAXLINES 5000

int get_line(char s[],int lim);
int readlines(char *lineptr[],int limit);
void writelines(char *v[],int limit);
void pstrncpy(char *to,char *from,int n);


int main(){
	char *lines[MAXCHARS];
	int nlines;
	nlines = readlines(lines,50);
	printf("%d\n",nlines);
	writelines(lines,nlines);
}
int get_line(char s[],int lim){
	int c,i;
	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n') s[i++] = c;
	if(c=='\n') s[i++] = c;
	s[i] = '\0';
	return i;
}


int readlines(char *lineptr[],int limit){
	int nlines = 0;
	int len;
	char *p,CurrentLine[MAXCHARS];
	while((len = get_line(CurrentLine,MAXCHARS)) > 0)  {
		if(nlines >= limit){
			return -1;
		} else {
			CurrentLine[len-1] = '\0';
			strncpy(p,CurrentLine,len);
			lineptr[nlines] = p;
			nlines++;
		}
	}
	printf("...pop\n" );
	return nlines;
}

void writelines(char *v[],int lim){
	while(lim-->0) printf("%s\n",*v++);
}
void pstrncpy(char *to,char *from,int n){
    while ((*to++ = *from++) && n-->0 )
        ;
}
