#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 1000

// these variables are declared as static because..
// ..they have to retain there value after each operation
static char allocbuff[MAX_LENGTH];
static char *allocp = &allocbuff[0]; // could also be written as static
                                        //char *allocp = allocbuff

char *salloc(int n);   // allocate n bytes from stack(i.e array alloc buff) ;
                  // returns a pointer to the beganning from the memory portion
void afree(char *p);   // frees a portion of memory portion

char *salloc(int n)
{
    if(allocbuff + MAX_LENGTH - allocp >= n)
    /*
     * for me the above condition was bit hard to understand
     * basically it checks if a stack have enought storage
     * for starters when no memory allocated then the address in allocbuff and
     *  allocp are equal
     * (i.e) allocbuff - allocp = 0  , 0 + MAX_LENGTH = MAX_LENGTH ? MAX_LENGTH >= n then allocate space
     * when alloc() have been called onece or several time the memory allocated , let it be 's'
     * allocbuff - s < 0 ; MAX_LENGTH + (allocbuff -s) would give the free memory we have
     */
    {
        allocp += n;   // moves the allocp forward by n bytes
        return allocp-n; // return the pointer pointing to beginning of the allocated block of memory
    }
    else{ // if no space is avaliable return NULL
        return NULL;
    }
}
void afree(char *p){
    //
    if(p >= allocbuff && p < allocbuff + MAX_LENGTH) allocp = p;
}

int isnumeric(char *s);
int isin(char *s,char c);

int isin(char *s,char c){
    while(*s != '\0'){
        if(*s == c)
            return 1;
    *s++;
    }
    return 0;
}

int isnumeric(char *c){
    while( (*c++) != '\0'){
        if (!isdigit(*c) && *c !='\0')
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int n_argc = argc;
    char *operators = salloc(20);
    char *operands[13];
    int op_i=0;
    int opr_i=0;
    strcpy(operators,"");
    while (argc-->1) {
        if (isin("-+x/",argv[argc][0])) {
            strcat(operators,argv[argc]);
            opr_i++;
        }
        else if (isnumeric(argv[argc])){
            operands[op_i++] = argv[argc];
        }
        else{
            printf("%s\n","Syntex Error!!");
            exit(1);
        }
    }
    while(n_argc-->0){
        if(n_argc %2 !=0){
            printf("%s ",operands[--op_i]);
        }else{
            printf("%c ",operators[--opr_i] );
        }
    }
    printf("\n");
    return 0;
}
