#include <iostream>

using namespace std;

//The following set of (almost the same) functions breaks the DRY principle/rule!
void swap2Ints(int &a, int &b)
{
  int c = a; a = b; b = c;
}

void swap2Doubles(double &a, double &b)
{
  double c = a; a = b; b = c;
}

void swap2Chars(char &a, char &b)
{
  char c = a; a = b; b = c;
}

struct PairOfDoubleAndChar
{
  double d;
  char c;
};

void swap2PairsOfDoubleAndChar(PairOfDoubleAndChar &a, PairOfDoubleAndChar &b)
{
  PairOfDoubleAndChar c = a; a = b; b = c;
}

ostream& operator<<(ostream &out, const PairOfDoubleAndChar& pair)
{
  out << "(" << pair.d << "," << pair.c << ")";
  return out;
}

void repeatYourselfDemo()
{
  cout << "repeatYourselfDemo()..." << endl;

  int i1 = 1, i2 = 2;
  swap2Ints(i1, i2);
  cout << "i1 = " << i1 << ", i2 = " << i2 << endl;

  double d1 = 1.5, d2 = 2.5;
  swap2Doubles(d1, d2);
  cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

  char c1 = 'a', c2 = 'b';
  swap2Chars(c1, c2);
  cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

  PairOfDoubleAndChar pair1 = {1.5, 'a'}, pair2 = {2.5, 'b'};
  swap2PairsOfDoubleAndChar(pair1, pair2);
  cout << "pair1 = " << pair1 << ", pair2 = " << pair2 << endl;
}

// declarations/prototypes of function templates
template <typename T>
void genericSwap(T&, T&);

// overload (genericSwap) template definition
template <typename T>
void genericSwap(T*, T*);

// user-defined function template specialisation prototype (for 'char')
template <>
void genericSwap(char*, char*);

/*
 * Notes:
 *
 * 1. Generic programming - programming in terms of a generic type
 *    instead of a specific type.
 *
 * 2. Parametric polymorphism - parts of the program (functions and/or data structures)
 *    can be parametrised by types.
 *
 * 3. A type is (parametrically) polymorphic if its declaration contains
 *    at least one type parameter/variable.
 *
 * 4. Use functions templates if you need functions that apply the same algorithm
 *    to a variety of types.
 *
 * 5. For a given function name, you can have a non template function,
 *    a template function, and an explicit specialization template function,
 *    along with overloaded versions of all of these
 *
 * 6. A specialization overrides the regular template, and a non template
 *    function overrides both.
 */

void genericFunctionsDemo1()
{
  cout << "genericFunctionsDemo1()..." << endl;

  int i1 = 1, i2 = 2;
  genericSwap(i1, i2);
  cout << "i1 = " << i1 << ", i2 = " << i2 << endl;

  double d1 = 1.5, d2 = 2.5;
  genericSwap(d1, d2);
  cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

  char c1 = 'a', c2 = 'b';
  genericSwap(c1, c2);
  cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

  PairOfDoubleAndChar pair1 = {1.5, 'a'}, pair2 = {2.5, 'b'};
  genericSwap(pair1, pair2);
  cout << "pair1 = " << pair1 << ", pair2 = " << pair2 << endl;
}

void genericFunctionsDemo2()
{
  cout << "genericFunctionsDemo2()..." << endl;

  int i1 = 1, i2 = 2;
  genericSwap(&i1, &i2); //or genericSwap<int>(&i1, &i2)
  cout << "i1 = " << i1 << ", i2 = " << i2 << endl;

  double d1 = 1.5, d2 = 2.5;
  genericSwap(&d1, &d2); //or genericSwap<double>(&d1, &d2)
  cout << "d1 = " << d1 << ", d2 = " << d2 << endl;

  char c1 = 'a', c2 = 'b';
  genericSwap<char>(&c1, &c2); //or genericSwap<double>(&d1, &d2)
  cout << "c1 = " << c1 << ", c2 = " << c2 << endl;

  PairOfDoubleAndChar pair1 = {1.5, 'a'}, pair2 = {2.5, 'b'};
  genericSwap<PairOfDoubleAndChar>(&pair1, &pair2);
  //or genericSwap<PairOfDoubleAndChar>(&pair1, &pair2)
  cout << "pair1 = " << pair1 << ", pair2 = " << pair2 << endl;
}

template <typename T>
T genFun()
{
  //T result{}; return result; // or just
  return T{}; // int i{}; ~ int i = 0; //default zeros, default constructors
}

void genericFunctionsDemo3()
{
  cout << "genericFunctionsDemo3()..." << endl;

  /*
   * error: no matching function for call to 'genFun',
   *   candidate template ignored: couldn't infer template argument 'T'
   *
   * cout << genFun() << endl;
   */

  cout << "genFun<char>() = " << genFun<char>()
       << ", sizeof(genFun<char>()) = " << sizeof(genFun<char>()) << endl;

  cout << "genFun<int>() = " << genFun<int>()
       << ", sizeof(genFun<int>()) = " << sizeof(genFun<int>()) << endl;

  cout << "genFun<double>() = " << fixed << genFun<double>()
       << ", sizeof(genFun<double>()) = " << sizeof(genFun<double>()) << endl;

  cout << "genFun<PairOfDoubleAndChar>() = "
       << fixed << genFun<PairOfDoubleAndChar>() << std::defaultfloat
       << ", sizeof(genFun<PairOfDoubleAndChar>()) = "
       << sizeof(genFun<PairOfDoubleAndChar>()) << endl;
}

template <typename T>
T genSumOf(T a, T b)
{
  return a + b;
}

PairOfDoubleAndChar operator+(const PairOfDoubleAndChar& p1,
                              const PairOfDoubleAndChar& p2)
{
  return PairOfDoubleAndChar{p1.d + p2.d, max(p1.c, p2.c)};
}

void genericFunctionsDemo4()
{
  cout << "genericFunctionsDemo4()..." << endl;

  int i1 = 1, i2 = 2;
  cout << "genSumOf(" << i1 << "," << i2 << ") = " << genSumOf(i1, i2) << endl;

  double d1 = 1.5, d2 = 2.5;
  cout << "genSumOf(" << d1 << "," << d2 << ") = " << genSumOf(d1, d2) << endl;

  //What does it mean to add two characters?
  char c1 = 'a', c2 = 'b';
  cout << "genSumOf(" << c1 << "," << c2 << ") = " << genSumOf(c1, c2) << endl;

  /*
   * Without:
   * PairOfDoubleAndChar operator+(const PairOfDoubleAndChar& p1,
   *                               const PairOfDoubleAndChar& p2)
   * we get:
   * error: invalid operands to binary expression
   *   ('PairOfDoubleAndChar' and 'PairOfDoubleAndChar')
   *
   * Still no constrained parametric polymorphism in C++
   * ('concepts' are plenned (in C++20) to address this)
   */

  PairOfDoubleAndChar p1 = {1.5, 'a'}, p2 = {2.5, 'b'};
  cout << "genSumOf(" << p1 << "," << p2 << ") = " << genSumOf(p1, p2) << endl;
}

int main()
{
  repeatYourselfDemo();
  cout << endl;
  genericFunctionsDemo1();
  cout << endl;
  genericFunctionsDemo2();
  cout << endl;
  genericFunctionsDemo3();
  cout << endl;
  genericFunctionsDemo4();

  return 0;
}

// definitions of function templates
template <typename T>
void genericSwap(T& a, T& b) //when arguments are sent by reference
{
  T c = a; a = b; b = c;
}

template <typename T>
void genericSwap(T* a, T* b) //when arguments are sent by pointer
{
  T c = *a; *a = *b; *b = c;
}

// user-defined function template specialisation (for 'char')
template <>
void genericSwap(char* a, char* b)
{
  cout << "user-defined genericSwap(): ";
  char c = *a; *a = *b; *b = c;
}