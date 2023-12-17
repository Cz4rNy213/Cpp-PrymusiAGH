#include <iostream>

int argByValue(int i)
{
  return 2 * i;
}

int argByReference(int &r)
{
  r *= 2;
  return 5 * r;
}

int argByPointer(int *p)
{
  *p *= 2; // = *p = *p * 2;
  return 5 * *p; // = 5 * (*p)
}

int* add(int *px, int *py){ //there was a problem because when int sum is created inside the func. we can not return pointer to it because it is available only inside the func
  int *sum = new int;
  *sum = *px + *py;
  return sum;
}

void swap2Ints(int *p1, int *p2){
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void swap2(int *px, int *py) //it does not work because we are replacing pointers only inside the func
{
  int *tmp = px;
  px = py;
  py = tmp;
}

int main()
{
  using std::cout;
  using std::endl;

  int x = 1;
  cout << "x = " << x << endl;

  cout << "Calling argByValue(x):" << endl;
  int y = argByValue(x);
  cout << "x = " << x << ", y = " << y << endl;

  cout << "Calling argByReference(x):" << endl;
  y = argByReference(x);
  cout << "x = " << x << ", y = " << y << endl;

  cout << "Calling argByPointer(&x):" << endl;
  y = argByPointer(&x);
  cout << "x = " << x << ", y = " << y << endl;

  int x1 = 1, y1 = 2;
  swap2Ints(&x1, &y1);
  cout << "x1 = " << x1 << ", y1 = " << y1 << endl; // should print: x = 2, y = 1

  int x2 = 1, y2 = 2;
  swap2(&x2, &y2);
  cout << "x2 = " << x2 << ", y2 = " << y2 << endl;

  return 0;
}