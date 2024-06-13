#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*
 * returns the length of string `s` 
 */
int pstrlen(char *s){
    int n = 0;
    while(*s++ != '\0')
        n++;
    return n;
}

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


int main()
{
    char trick[100] ="A clever brown fox jump of the lazy dog";
    char goodwords[20] ="lazy dog";
    char badwords[20] = "stealthy cat";

    int m = pstrend(trick,goodwords);
    int n = pstrend(trick,badwords);


    printf("%d\n",pstrlen(trick));
    printf("%s\n",trick);
    printf("%d:%d\n",m,n);
}
