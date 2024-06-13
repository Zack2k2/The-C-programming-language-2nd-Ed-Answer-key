#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// return true is word is numeric
int isnum(char *word);
void pol_exp(int argc,char *argv[],char *lines[]);
// appends string s to the begaining of base_string
void appstart(char *base_string, char *s );

void appstart(char *base_string,char *s){
    char *tmps;
    strcpy(tmps,base_string);
    for(int i = 0; i < strlen(base_string);i++) base_string[i] = '\0'; // empty the string
    // base_string[0] = '\0'; // might test this leter
    strcpy(base_string,s);
    strcat(base_string,tmps);
}

int startswith_char(char *base_string,char c);
int endswith_char(char *base_string,char c);

int startswith_char(char *base_string,char c){
    return (base_string[0] == c);
}
int endswith_char(char *base_string,char c){
    return (base_string[strlen(base_string)-1] == c);
}


int isnum(char *word){
    int i = 0,sign = 1;

    while (word[i] == ' ') i++;
    if(word[i] == '-') i++;

    while(word[i] != '\0') {
        if(word[i] >= '0' && word[i] <= '9') i++;
        else return FALSE;
    }
    return TRUE;
}


void pol_exp(int argc,char *argv[],char *lines[],int line_index){
    int argv_index = argc;
    //int line_index = 0;
    char sub_exp[100];
    printf("..\n" );
    if (argc < 3) {
        return;
    }
    // at least 3 characters must be present for
    while(argv_index >= 3){
        if ( // For expression like 3 9 + ; <num1> <num2> op
            (argv[argv_index][0]=='+' || argv[argv_index][0] == '-' || argv[argv_index][0] == '*' || argv[argv_index][0] == '/')
            && isnum(argv[argv_index-1])
            && isnum(argv[argv_index-2])
            )
            {
                printf("..\n" );
                strcpy(sub_exp,"(");
                printf("%s\n",lines[line_index] );
                strcat(sub_exp,argv[argv_index-2]);
                strcat(sub_exp,argv[argv_index]);
                strcat(sub_exp,argv[argv_index-1]);
                strcat(sub_exp,")");
                lines[line_index] = &sub_exp[0];
                sub_exp[0] = '\0';
                line_index++;
                printf("..\n" );
        }
        else if (  // for expression like <num1> (expr) op
            (argv[argv_index][0]=='+' || argv[argv_index][0] == '-' || argv[argv_index][0] == '*' || argv[argv_index][0] == '/')
            && startswith_char(argv[argv_index-1],'(')
            && endswith_char(argv[argv_index-1],')')
            && isnum(argv[argv_index-2])
                )
            {
                strcpy(sub_exp,"(");
                strcat(sub_exp,argv[argv_index-2]);
                strcat(sub_exp,argv[argv_index]);
                strcat(sub_exp,argv[argv_index-1]);
                strcat(sub_exp,")");
                lines[line_index++] = &sub_exp[0];
                sub_exp[0] = '\0';
        }
        else if( // for expression like (exp1) (exp2) op
            (argv[argv_index][0]=='+' || argv[argv_index][0] == '-' || argv[argv_index][0] == '*' || argv[argv_index][0] == '/')
            && startswith_char(argv[argv_index-1],"(") && endswith_char(argv[argv_index-1],")")
            && startswith_char(argv[argv_index-2],"(") && endswith_char(argv[argv_index-2],")")
            )
            {
                strcpy(sub_exp,"(");
                strcat(sub_exp,argv[argv_index-2]);
                strcat(sub_exp,argv[argv_index]);
                strcat(sub_exp,argv[argv_index-1]);
                strcat(sub_exp,")");
                lines[line_index++] = &sub_exp[0];
                sub_exp[0] = '\0';
            }
        else if(
            (argv[argv_index][0]=='+' || argv[argv_index][0] == '-' || argv[argv_index][0] == '*' || argv[argv_index][0] == '/')    &&
            (argv[argv_index-1][0]=='+' || argv[argv_index-1][0] == '-' || argv[argv_index-1][0] == '*' || argv[argv_index-1][0] == '/')
            )
            {
                strcpy(sub_exp,argv[argv_index]);
                lines[line_index++] = &sub_exp[0];
                sub_exp[0] = '\0';
            }
        else if(
            (argv[argv_index][0]=='+' || argv[argv_index][0] == '-' || argv[argv_index][0] == '*' || argv[argv_index][0] == '/') &&
            ()
            )
            {

            }
        argv_index--;
    }
}

int main(int argc, char  *argv[]) {
    char *lines[10];
    pol_exp(argc,argv,lines);
    for (size_t i = 0; i < 10; i++) {
        printf("%s\n",lines[i] );
    }
    return 0;
}
