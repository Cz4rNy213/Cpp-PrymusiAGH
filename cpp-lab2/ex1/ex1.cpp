#include <iostream>

// A namespace is a (named) scope
namespace MyLib {
    int add(int x, int y) { return x + y; } // definition of function "add"
    int sub(int x, int y); // declaration of function "sub"
    extern int v; // declaration of variable "v"
}

int MyLib::v = 1;

int MyLib::sub(int x, int y)
{
    return x - y;
}
/*
* A namespace is open - you can add names to it from several separate
* namespace declarations (they can also be written in different files)
*/
namespace MyLib {
    int mul(int x, int y) { return x * y; }
    int aToB(int a, int b);
}

int g_counter = 0; // a global variable

// a global function
int aToB(int a, int b)
{
    if (b <= 0) { return 1; }
    else { return a * aToB(a, b - 1); }
}

extern int g1;
int MyLib::aToB(int a, int b)
{
    int r = 1; // local variable
    static int sl_aToBCallCounter = 0; // static local variable

    for (int i = 1; i <= b; ++i) { r *= a; }

    sl_aToBCallCounter++;

    { // it is a new scope!
    using namespace std;
    cout << "sl_aToBCallCounter = " << sl_aToBCallCounter << endl;
    cout<<"g1 = "<<g1;
    }

    return r;
}

int g1 = 1;
using MyLib::add;

int main()
{
    using namespace std; // using-directive: make ALL names from std accessible
    using MyLib::mul; // using-declaration: add a name ("mul") to a local scope
    cout << "add(1,2) = " << add(1,2) << endl;
    cout << "mul(3,5) = " << mul(3,5) << endl;
    cout << "MyLib::sub(5,2) = " << MyLib::sub(5,2) << endl;

    { // it is a new scope!
        using MyLib::aToB;
        cout << "aToB(5,2) = " << aToB(5,2) << endl;
        cout << "aToB(3,3) = " << aToB(3,3) << endl;

        // to access the global function aToB we use "::" prefix
        cout << "::aToB(3,4) = " << ::aToB(3,4) << endl;
    }

    // now we need the fully qualified name (no using MyLib::aToB in this scope)
    cout << "MyLib::aToB(2,6) = " << MyLib::aToB(2,6) << endl;

    int *p = new int; // new-allocated/dynamic memory/data/object
    *p = 5;
    cout << "*p = " << *p << endl;
    delete p;

    return 0;
}