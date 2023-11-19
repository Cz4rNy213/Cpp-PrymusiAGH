#include <iostream>

void castDemo1()
{
  int x = 1;
  int *p1 = &x;

  printf("&x = %p, x = %d\n", &x, x);
  printf("&p1 = %p, p1 = %p\n", &p1, p1);

  printf("&x = %p, x = %d\n", (void*) &x, x);
  printf("&p1 = %p, p1 = %p\n", (void*) &p1, (void*) p1);

  printf("&x = %p, x = %d\n", static_cast<void*>(&x), x);
  printf("&p1 = %p, p1 = %p\n", static_cast<void*>(&p1), static_cast<void*>(p1));

  printf("&x = %p, x = %d\n", reinterpret_cast<void*>(&x), x);
  printf("&p1 = %p, p1 = %p\n", reinterpret_cast<void*>(&p1), reinterpret_cast<void*>(p1));

  const int y = 2;
  //int *p2 = &y; // !!!
  int *p2 = const_cast<int *>(&y);
  printf("y = %d, *p2 = %d\n", y, *p2);
}

void castDemo2()
{
  unsigned int a[] = { 0x01234567, 0x89ABCDEF };
  unsigned char *pc = reinterpret_cast<unsigned char*>(a);
  unsigned short *ps = reinterpret_cast<unsigned short*>(a);
  unsigned int *pi = reinterpret_cast<unsigned int*>(a);
  unsigned long *pl = reinterpret_cast<unsigned long*>(a);

  for (int i = 0; i < 2; ++i) {
    printf("pc[%i] = %X\n", i, pc[i]);
    printf("ps[%i] = %X\n", i, ps[i]);
    printf("pi[%i] = %X\n", i, pi[i]);
    printf("pl[%i] = %lX\n", i, pl[i]);
  }
}

int main()
{
//   castDemo1();
  castDemo2();
  return 0;
}