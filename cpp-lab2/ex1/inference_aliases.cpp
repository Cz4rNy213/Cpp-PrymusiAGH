#include <iostream>

int main()
{
  using namespace std;
  auto x1 = 1; // int x1 = 1;
  auto x2 = 2uL; // unsigned long x2 = 2;
  auto x3 = 2.71; // double x3 = 2.71;
  auto x4 = 3.14f; // float x4 = 3.14;

  decltype (x3) x5 = 1.23; // double x5 = 1.23;
  using t1 = decltype (x2);
  t1 x6 = 5; // unsigned long x6 = 5

  typedef unsigned long t2;
  t2 x7 = 6;

  cout << "sizeof(x1) = " << sizeof(x1) << endl;
  cout << "sizeof(x2) = " << sizeof(x2) << endl;
  cout << "sizeof(x3) = " << sizeof(x3) << endl;
  cout << "sizeof(x4) = " << sizeof(x4) << endl;
  cout << "sizeof(x5) = " << sizeof(x5) << endl;
  cout << "sizeof(x6) = " << sizeof(x6) << endl;
  cout << "sizeof(x7) = " << sizeof(x7) << endl;
}