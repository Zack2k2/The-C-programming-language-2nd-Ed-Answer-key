char *strcmp(char *s,char *t);
char *strcmp(char *s,char *t){
    for (; *s == *t;*s++,*t++) if(*s=='\0') return 0;
    return *s-*t;
}
