#include <iostream>
#include <cmath>

using namespace std;

void fun1()
{
  float f1 = 0.1f, f2 = 0.3f, f3 = 0.455f;
  float f4 = (f1 + f2) + f3;
  float f5 = f1 + (f2 + f3);

  if (0 < f4 - f5 < 1e-6) { //if sprawdza czy ta wartość jest mniejsza od marginesu, bo ogólnie 
                              //liczby float mają na końcu błędy ze względu na ograniczoną liczbę bitów i nie powinno sie ich porównywac za pomocą ==
      cout << "f4 == f5" << endl;
  } else {
      cout << "f4 != f5" << endl;
  }
}

int absInt(int x)
{
  return (x >= 0) ? x : -x;
}

void switchDemo(char c)
{
  switch (c) {
  case 'y':
     cout << "'y' matched" << endl;
     break;
  case 'n':
     cout << "'n' matched" << endl;
     break;
  case 'c':
     cout << "'c' matched" << endl;
     break;
  default:
     cout << "Default case, please select 'y','n' or 'c'" << endl;
  }
}

int main()
{
  fun1();
  switchDemo('y');
  cout << "absInt(-3) = " << absInt(-3) << endl;
  return 0;
}