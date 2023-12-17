#include <iostream>
#include <string>
#include <vector>
#include "Pair.h"
#include "stack_vec_impl.h"
#include "ArrayStack.h"

using namespace std;


void subtypeAndParametricPolymorphismDemo1()
{
  cout << "subtypeAndParametricPolymorphismDemo1()..." << endl;

  Stack<int> *p1 = new StackVectorBasedImpl<int>{};
  cout << "Empty stack: p1->size() = " << p1->size() << endl;

  cout << "pushing 3 elements..." << endl;
  p1->push(1);
  p1->push(2);
  p1->push(3);
  cout << "p1->size() = " << p1->size() << endl;
  cout << "p1->peek() = " << p1->peek() << endl;

  cout << "popping one element..." << endl;
  p1->pop();
  cout << "p1->size() = " << p1->size() << endl;
  cout << "p1->peek() = " << p1->peek() << endl;

  delete p1;
}

void subtypeAndParametricPolymorphismDemo2()
{
  cout << "subtypeAndParametricPolymorphismDemo2()..." << endl;

  Stack<string> *p2 = new StackVectorBasedImpl<string>{};
  cout << "Empty stack: p2->size() = " << p2->size() << endl;

  cout << "pushing 3 elements..." << endl;
  p2->push("aaa");
  p2->push("bbb");
  p2->push("ccc");
  cout << "p2->size() = " << p2->size() << endl;
  cout << "p2->peek() = " << p2->peek() << endl;

  cout << "popping one element..." << endl;
  p2->pop();
  cout << "p2->size() = " << p2->size() << endl;
  cout << "p2->peek() = " << p2->peek() << endl;

  delete p2;
}

void subtypeAndParametricPolymorphismDemo3()
{
  cout << "subtypeAndParametricPolymorphismDemo3()..." << endl;

  Stack<Pair<double,Pair<int,string>>> *p3 =
            new StackVectorBasedImpl<Pair<double,Pair<int,string>>>{};
  cout << "Empty stack: p3->size() = " << p3->size() << endl;

  cout << "pushing 3 elements..." << endl;
  p3->push(Pair<double,Pair<int,string>>{1.1, Pair<int,string>{1,"aaa"}});
  p3->push(Pair<double,Pair<int,string>>{2.2, Pair<int,string>{2,"bbb"}});
  p3->push(Pair<double,Pair<int,string>>{3.3, Pair<int,string>{3,"ccc"}});
  cout << "p3->size() = " << p3->size() << endl;
  cout << "p3->peek() = " << p3->peek() << endl;

  cout << "popping one element..." << endl;
  p3->pop();
  cout << "p3->size() = " << p3->size() << endl;
  cout << "p3->peek() = " << p3->peek() << endl;

  delete p3;
}

template<typename T>
struct ExpansionStrategy {
    void expand(std::vector<std::vector<T>>& array, size_t& capacity) {
        capacity *= 2;
        array.resize(capacity);
    }
};

int main() {
    subtypeAndParametricPolymorphismDemo1();
    cout << endl;
    subtypeAndParametricPolymorphismDemo2();
    cout << endl;
    subtypeAndParametricPolymorphismDemo3();

    
    ExpansionStrategy<int> expansionStrategy;
    Stack<vector<int>> *p3 = new ArrayStack<vector<int>, ExpansionStrategy<int>>(5, expansionStrategy);


    return 0;
}
