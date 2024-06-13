#include <stdio.h>
void swap(int *,int *);

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main(int argc, char const *argv[]) {

  return 0;
}
