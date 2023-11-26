#include <iostream>

void pointersDemo1()
{
  int x = 1;
  int *p1 = &x;
  int **pp1 = &p1;

  printf("&x = %p, x = %d\n", &x, x);
  printf("&p1 = %p, p1 = %p\n", &p1, p1);
  printf("&pp1 = %p, pp1 = %p\n", &pp1, pp1);

  printf("*p1 = %d\n", *p1);
  printf("**pp1 = %d\n", **pp1);

  printf("About to execute *p1 = 2...\n");
  *p1 = 2;
  printf("x = %d\n", x);

  printf("About to execute **pp1 = 3...\n");
  **pp1 = 3;
  printf("x = %d\n", x);
  x = 5;
  const int y = 2;
  const int *p2 = &y;
  p2 = &x;
  x = 7;
  printf("*p2 = %d\n", *p2);

  const int * const p3 = &x; // a pointer to a const can be used for a non-const
  //int *p2 = &y; // but not vice-versa
  printf("*p3 = %d\n", *p3);
  //p3 = &y; // !!! cannot reassign a const pointer

  //constexpr int cexpr = 3;
  //int *p4 = &cexpr; // you cannot read a constexpr address
}

void referencesDemo()
{
  double x = 2.71;
  double &rx = x;
  //double &ry; // !!! declaration of reference 'ry' requires an initializer
  printf("x = %f\n", x);
  printf("rx = %f\n", rx);

  double *px = &x;
  double *& rpx = px;
  printf("&x = %p, px = %p\n", &x, px);
  printf("rpx = %p\n", rpx);

  //double &* prx = &rx; // !!! you cannot create a pointer to a reference
}

int sumArr(int (*p)[5])
{
  int sum = 0;
  for (int i = 0; i < 5; i++) {
    sum += (*p)[i]; // or sum += *((*p) + i);
  }
  return sum;
}

void pointersDemo2()
{
  int a[] = {1, 2, 3, 4, 5};
  int b[] = {1, 2, 3, 4, 5, 6};
  int *p1 = a;

  printf("&a = %p, a = %p, &a[0] = %p\n",&a, a, &a[0]);
  printf("a[0] = %d, *p1 = %d\n", a[0], *p1);

  // int (*p2)[] = &a; // !!!
  // int (*p2)[5] = &b; // !!!
  int (*p2)[5] = &a;
  printf("&p2 = %p, p2 = %p, *p2 = %p, **p2 = %d, (*p2)[2] = %d\n",
         &p2, p2, *p2, **p2, (*p2)[2]);

  printf("sumArr(a) = %d\n", sumArr(&a));
  //printf("sumArr(a) = %d\n", sumArr(&b)); // !!!

  constexpr int asize = sizeof (a) / sizeof (int);
  // Print all elements of "a"
  for (int i = 0; i < asize; ++i) {
    printf("a[%d] = %d\n", i, a[i]);
  }

  // The same but with the use of different notation
  for (int i = 0; i < asize; ++i) {
    printf("*(a + %d) = %d\n", i, *(a + i)); // a[i] = *(a + i)
  }

  // The same but this time with the use of a pointer
  int *p3 = a;
  for (int i = 0; i < asize; ++i) {//or for (int i = 0; i < asize; ++i, p3++)
      printf("*p3 = %d\n", *p3);
      p3++;
  }
}


int f1(int i) { return i; }
int f2(int i) { return 10 * i; }
int f3(int i) { return 100 * i; }

double f4(char c)
{
  return (c == 'a') ? 3.14 : 2.71;
}

int* f5(double *x)
{
  int *res = new int;
  *res = (*x > 0) ? -1 : 1;
  return res;
}

int* f6(double *x)
{
  int *res = new int;
  *res = (*x > 0) ? 10 : 0;
  return res;
}

int* (*f7(double (*pf)(char), int *p1))(double *)
{
  double res1 = (*p1 > 0) ? pf('a') : pf('b');
  if (res1 > 0) return f5;
  else return f6;
}

void pointersDemo3()
{
  typedef int (*PInt_Fun_Int_T)(int);
  PInt_Fun_Int_T fs[] = { f1, f2, f3 };

  for (int i = 0; i < 3; ++i) {
     printf("fs[%d](%d) = %d\n", i, i, fs[i](i));
  }
  printf("\n");

  // Although, in C++, you cannot increment a pointer to a function
  // you can increment a pointer to such a pointer
  PInt_Fun_Int_T *pf = &fs[0]; // a pointer to a pointer to a function :)
  for (int i = 0; i < 3; ++i) {
    printf("pf(%d) = %d\n", i, (*pf)(i));
    pf++;
  }
}

void pointersDemo4()
{
  double x = 1;
  //int* (*f7(double (*pf)(char), int *p1))(double *)
  int* (*(*p7)(double(*)(char), int*)) (double*) = f7;
  printf("*f7(f4,f6(&x))(&x) = %d\n", *f7(f4,f6(&x))(&x));
  printf("*p7(f4,f6(&x))(&x) = %d\n", *p7(f4,f6(&x))(&x));
}

void dumpNBytesFrom(unsigned char* p, int n)
{
  for (int i = 0; i < n; i++ ){
    printf("p[%d] = %x\n", i, *p);
    p++;
  }
}

int main()
{
  pointersDemo1();
  referencesDemo();
  pointersDemo2();
  pointersDemo3();
  pointersDemo4();

  return 0;
}