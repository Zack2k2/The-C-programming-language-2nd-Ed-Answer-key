#include <bits/floatn-common.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20



int binsearch_v2(int key, int array[], int size);
int binsearch_v2(int key, int array[], int size){

    int low,mid,high;
    low = 0;
    high = size - 1;

    while(low < high)
    {
        mid = (low+high)/2;
        if(array[mid] < key ){
            low = mid+1;
        } else 
            high = mid;
    }
    if(array[low] == key) return low;
    return -1;
}

int main(int argc, char *argv[]){
    if(argc < 2) exit(1);
    
    int v[SIZE];
    int last_value;
    int n;
    
    n = atoi(argv[1]);
    
    printf("%d\n",n);
    int p =0;
    for(int index = 1; index < argc-1; index++){
        
        v[index-1] = atoi( argv[index]);
        //p++;

    }
    printf("array values:\n");
    for (int i = 0; i <p; i++) printf("%d\n",v[i]);
    last_value=atoi(argv[argc-1]);


    
    int key = last_value;
    printf("pr");
    int position;
    position = binsearch_v2(key,v,argc-1);
    printf("The found position is : %d\n",position);
}
