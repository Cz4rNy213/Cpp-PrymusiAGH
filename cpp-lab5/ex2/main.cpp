#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

class ConstMemberFuncDemo
{
public:
   ConstMemberFuncDemo(double x, double y) : x_{x}, y_{y}, i_{1}, cache_{0} {/*const int i_ = 1;*/}

  double x() const { return x_; } // const member function
  double y() const { return y_; } // as above - const member function
  void constMemberFunction() const; // (1)

   /*
   * A pair of functions with the same name and parameter list
   * but one marked as 'const'
   */
   void function1() { cout << "function1()..." << endl; }
   void function1() const { cout << "function1() const..." << endl; }

   //non-const member function
   void nonConstFunction() {
     //non-const member function can access a const-member function
     cout << "nonConstFunction()..." << " x = " << x() << endl;
   }
private:
  double x_;
  double y_;
  const int i_;
  mutable double cache_; // <- mutable data member
};

/*
 * The 'const' suffix is needed both in the declaration (see the line (1) above)
 * and the definition (right below)
 */
void ConstMemberFuncDemo::constMemberFunction() const {
  cout << "[" << x() << ", " << y() << "]" << endl;
  //the function is declared as const => cannot update the state of the object
  //x_++; // error!
  cache_ += i_; // 'const' member function CAN change mutable data members
}

void gfConstRef(const ConstMemberFuncDemo& cmfd)
{
  cmfd.function1();
}

void gfNonConstRef(ConstMemberFuncDemo& cmfd)
{
  cmfd.function1();
}

int main()
{
  const ConstMemberFuncDemo constObj(1,2);
  constObj.constMemberFunction(); //OK, calling const member function for a const obj
  //constObj.nonConstFunction(); //Cannot call non-const function for a const object

  ConstMemberFuncDemo nonConstObj(10,11);
  nonConstObj.constMemberFunction();
  nonConstObj.nonConstFunction();

  cout << "Calling constObj.function1()..." << endl;
  constObj.function1(); // 'function1() const' is called here

  cout << "Calling nonConstObj.function1()..." << endl;
  nonConstObj.function1(); // 'function1()' is called here

  cout << "Calling gfConstRef(constObj)..." << endl;
  gfConstRef(constObj);
  cout << "Calling gfConstRef(nonConstObj)..." << endl;
  gfConstRef(nonConstObj);

  //gfNonConstRef(constObj); //cannot call the function directly, but...
  cout << "Calling gfNonConstRef(const_cast<ConstMemberFuncDemo&>(constObj))..." << endl;
  gfNonConstRef(const_cast<ConstMemberFuncDemo&>(constObj)); //...const_cast solves the problem

  cout << "Calling gfNonConstRef(nonConstObj)..." << endl;
  gfNonConstRef(nonConstObj);
  return 0;
}