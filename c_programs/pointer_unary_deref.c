#include <stdio.h>
int main(int argc, char const *argv[]) {
  int x = 5;
  printf(":%d\n",*(&x));
  return 0;
}
