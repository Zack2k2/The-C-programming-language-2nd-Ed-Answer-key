#include <stdio.h>
int binary_search_left(int array[],int x,int n);
int main(){
    int num_array[32000];
    int i;
    for(i=0;i<=32000;i++){
      num_array[i] = 1 +((i-1)*(2));
    }
    int found;
    found = binary_search_left(num_array,25671,32000);
    printf("%d:%d\n",num_array[found],found);

}

int binary_search_left(int array[],int x,int n){
  int left,right,mid;
  left = 0;
  right = n;
  while(right > left){
    mid = (left + right) / 2;
    if (x >= array[mid]){
      left= mid+1;
    }else{
      right = mid;
    }
  }
  return left;
}
