#include <stdio.h>
#define TRUE 1
#define FALSE 0


int pstrcat(char *s, char *t);

int pstrlen(char *s);

int pstrend(char *s, char *t);

/*
 * Reverses a string `s` such that
 * s[0] is swaped with s[n-1]
 * s[1] is swaped with s[n-2]
 * s[2] is swaped with s[n-2]
 * and so on
 * */
void preverse(char *s);

/*
 * swaps str[x] with str[y]
 * */
void swap_char(char *str, int x, int y){
    char temp;
    temp = *(str + x);
    *(str + x) = *(str + y);
    *(str + y) = temp;
}

/*
 * getline: get line and loads it into `s`
 * making sure that the length of `s` doesn't
 * exceed `lim`,returns the length of input line.
 * */
int homemadegetline(char *s, int lim);

/*
 *  returns TRUE if `t` occurs at the end of `s`
 *  FALSE otherwise.
 *  the string `t` must be smaller then `s`
 * */
int pstrend(char *s, char *t){
    int ns,nt; // lengths of both strings.
    ns = nt = 0;
    
    ns = pstrlen(s);  // get lengths of both strings.
    nt = pstrlen(t);

    s += ns;
    t += nt;

    if (nt > ns) return FALSE;

    
    while(nt --> 0){
        if(*s-- != *t--){
            return FALSE;
        } 
    }


    return TRUE;
    //printf()

}



int pstrcat(char *s,char *t){

    while(*s++ != '\0')
        ;
 
    s--; // discard the null character.
    while((*s++ = *t++)!='\0')
        ;

    return TRUE;
}
int pstrlen(char *s){
    int n = 0;
    while(*s++ != '\0')
        n++;
    return n;
}


void preverse(char *s){
    int length = pstrlen(s); 
    int n_swaps = length/2;
    
    char *last_char = (s + length);
    for(int index = 0; index < n_swaps; index++){
        swap_char(s,index,(length-index-1));
    }

}


int homemadegetline(char *s, int lim){
    int length = 0;
    int c,i;

    while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
    {
        *s++ = c;
        length++;
    }
    if (c == '\n'){
        *(s+length) = '\n';
        
    }
    *(s+length) = '\0';
    return length;

}

