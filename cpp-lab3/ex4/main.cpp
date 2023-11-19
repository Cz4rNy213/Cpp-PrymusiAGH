#include <iostream>
#include <bitset>

void bitwiseOpsDemo1()
{
  unsigned int x = 5;
  unsigned int y = 10;

  printf("x || y = %u (0x%x)\n", x || y, x || y);
  printf("x | y = %u (0x%x)\n", x | y, x | y);

  printf("x && y = %u (0x%x)\n", x && y, x && y);
  printf("x & y = %u (0x%x)\n", x & y, x & y);

  printf("x ^ y = %u (0x%x)\n", x ^ y, x ^ y);
  printf("~x = %u (0x%x)\n", ~x, ~x);

  printf("y << 1 = %u (0x%x)\n", y << 1, y << 1);
  printf("y >> 1 = %u (0x%x)\n", y >> 1, y >> 1);
  int res = ~((4 | 1) << 2) & 7;
  int res2 = ((4 ^ 2) | 16) >> 1;
  printf("%d\n", res);    
  printf("%d\n", res2);
}

int main()
{
  bitwiseOpsDemo1();
  
  return 0;
}