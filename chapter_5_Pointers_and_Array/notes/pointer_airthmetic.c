#include <stdio.h>

int main()
{
    int *ip;
    int arr[15] = {2,3,5,7,11,13,17,19,31,59,107,127,239,251};

    ip = &(arr[0]);

    printf("ip contains [%2d] on address [%p]\n",*ip,ip);

    int *a;
    int *b;
    int c;

    a = ip + 3;
    b = a;




    printf("a contains [%2d] on address [%2p]\n",*a,a);
    c = *a++;
    printf("c contains [%2d] on address [%2p]\n",c,&c);
    printf("a contains [%2d] on address [%2p]\n",*a,a);
    (*a)++;
    printf("a contains [%2d] on address [%2p]\n",*a,a);
    

    a = a + 5;
    printf("a contains [%2d] on address [%2p]\n",*a,a);

    a = a - 2;
    printf("a contains [%2d] on address [%2p]\n",*a,a);
}
