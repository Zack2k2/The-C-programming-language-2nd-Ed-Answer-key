#include <stdio.h>
#include <string.h>

void evaluate_experation(char *line);
void SplitString(char *OutputString,char *BaseString,char *KnifeString);
void SplitString(char *OutputString[],char *BaseString,char *KnifeString){
    int BaseStringIndex = 0;
    int KnifeStringLengthDuringLoops = 0;

    while(strstr(BaseString,KnifeString) != NULL)
}

void evaluate_experation(char *line){
    int len = strlen(line);
    int index = 0;
    len--;
    char *exp_string[5];
    while(len-->0){
        if(line[len] != ' ' && line[len] != '\t' && line[len] != '\n'){
            printf("%s\n","=" );
            exp_string[index++] = (line+len);
        }
    }
    while(index-->0) printf("%s\n",exp_string[index]);
}

int main(int argc, char const *argv[]) {
    char *exp = "12 5 +";
    evaluate_experation(exp);
    return 0;
}
