#include <iostream>
#include <string>
#include <vector>

using namespace std;

//The following two classes break the DRY principle/rule!
class PairOfIntAndString
{
public:
  PairOfIntAndString(int i, string s) : i_{i}, s_{s} {}
  int fst() const { return i_; }
  string snd() const { return s_; }

private:
  int i_;
  string s_;
  friend ostream& operator<<(ostream&, const PairOfIntAndString&);
};

ostream& operator<<(ostream& out, const PairOfIntAndString& rp)
{
  out << "(" << rp.i_ << "," << rp.s_ << ")";
  return out;
}

class PairOfDoubleAndPairOfIntAndString
{
public:
  PairOfDoubleAndPairOfIntAndString(double d, PairOfIntAndString p) : d_{d}, pIntStr_{p} {}
  double fst() const { return d_; }
  PairOfIntAndString snd() const { return pIntStr_; }

private:
  double d_;
  PairOfIntAndString pIntStr_;
  friend ostream& operator<<(ostream&, const PairOfDoubleAndPairOfIntAndString&);
};

ostream& operator<<(ostream& out, const PairOfDoubleAndPairOfIntAndString& rp)
{
  out << "(" << rp.d_ << "," << rp.pIntStr_ << ")";
  return out;
}

void repeatYourselfWithClassesDemo()
{
  cout << "repeatYourselfDemo2()..." << endl;

  PairOfIntAndString pIntStr(1, "abc");
  cout << "pIntStr = " << pIntStr << endl;
  PairOfDoubleAndPairOfIntAndString pDoubleIntStr{1.5, pIntStr};
  cout << "pDoubleIntStr = " << pDoubleIntStr << endl;
}

//forward declaration of class Pair
template <typename F, typename S>
class Pair;

//function (operator) template prototype/declaration
template <typename F, typename S>
ostream& operator<<(ostream&, const Pair<F,S>&);

//class template with a default type parameter S => Pair<int> = Pair<int,int>
template <typename F, typename S = F> //
class Pair
{
public:
  Pair(F fst, S snd) : fst_{fst}, snd_{snd} {}
  F fst() const { return fst_; }
  S snd() const;

private:
  F fst_;
  S snd_;
  friend ostream& operator<< <>(ostream&, const Pair<F,S>&); // 1:1 friendship
  //or
  //friend ostream& operator<< <F,S>(ostream&, const Pair<F,S>&);

  /*
   * 1:1 friendship, i.e. if we have:
   * Pair<int,string>
   * then only
   * ostream& operator<<(ostream&, const Pair<int,string>&)
   * is its friend
   */
};

//member function definition example
template <typename F, typename S>
S Pair<F,S>::snd() const
{
  return snd_;
}

template <typename F, typename S>
ostream& operator<<(ostream& out, const Pair<F,S>& rp)
{
  out << "(" << rp.fst_ << "," << rp.snd_ << ")";
  return out;
}

void genericClassesDemo1()
{
  cout << "genericClassesDemo1()..." << endl;

  //Using a template class
  Pair<int, string> pIntStr{1, "abc"};
  cout << "pIntStr = " << pIntStr << endl;

  Pair<double, Pair<int, string>> pDoubleIntStr{1.5, pIntStr};
  cout << "pDoubleIntStr = " << pDoubleIntStr << endl;

  Pair<double> pDblDbl{1.5, 2.5};
  cout << "pDblDbl = " << pDblDbl << endl;
}

template <typename T, int n>
class SafeArray
{
public:
  using iterator = T*;
  explicit SafeArray(const T& v = {}) { for (int i = 0; i < n; i++) array[i] = v; }
  T& operator[](int i);
  T operator[](int i) const;

  //To be able to use the range-based for loop
  iterator begin() { return &array[0]; }
  iterator end() { return &array[n]; } // the address of the (n+1) element

private:
  T array[n];
};

template <typename T, int n>
T& SafeArray<T,n>::operator[](int i)
{
  if (i < 0 || i >= n) throw out_of_range("Error: array index out of range");
  return array[i];
}

template <typename T, int n>
T SafeArray<T,n>::operator[](int i) const
{
  if (i < 0 || i >= n) throw out_of_range("Error: array index out of range");
  return array[i];
}

void genericClassesDemo2()
{
  cout << "genericClassesDemo2()..." << endl;

  //SafeArray<int, 5> demo
  constexpr int saInt5Size = 5;
  SafeArray<int, saInt5Size> saInt5{};
  saInt5[2] = 20;

  cout << "saInt5 = " << "[ ";
  for (auto e: saInt5) {
    cout << e << " ";
  }
  cout << "]" << endl;

  //SafeArray<string, 3> demo
  SafeArray<string, 3> saString3{"abc"};
  saString3[2] = "def";

  cout << "saString3 = " << "[ ";
  for (auto e: saString3) {
    cout << e << " ";
  }
  cout << "]" << endl;

}

int main()
{
  repeatYourselfWithClassesDemo();
  cout << endl;
  genericClassesDemo1();
  cout << endl;
  genericClassesDemo2();

  return 0;
}