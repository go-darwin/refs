// https://gist.github.com/YukiSakamoto/3776193
//
//  $ clang -o ./src/random ./src/random.c

#include <stdio.h>

/*
This source is testing for address layout randomization.
If ASLR is enabled, output of this program will be variable.
*/

int main(void)
{
  printf("main: %p, ", main);
here:
  printf("here: %p\n", &&here);
  return 0;
}
