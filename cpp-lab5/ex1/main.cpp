#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class ClassThatCountsItsInstances
{
private:
  static int counter;

public:
  ClassThatCountsItsInstances()
  {
    counter++;
  }
  ~ClassThatCountsItsInstances()
  {
    counter--;
  }
};
int ClassThatCountsItsInstances::counter = 0;

class StaticMembersDemo
{
public:
  static void staticMemberFunction1();

  // in-class static member function definition
  static void staticMemberFunction2()
  {
    cout << "staticMemberFunction2()..." << endl;
  }

  void nonStaticMemberFunction();

private:
  // non-const static data member must be initialized out of line!
  // static int staticDataMember = 0;
  static int staticDataMember;                // <- only declaration
  static const int constStaticDataMember = 0; // OK, const
  int nonStaticDataMember = 0;
};

// static member data is shared by all objects of the class
int StaticMembersDemo::staticDataMember = 0; // <- definition + initialisation

// no "static" prefix - it is only used in declarations
void StaticMembersDemo::staticMemberFunction1()
{
  cout << "staticMemberFunction1()..." << endl;
  staticDataMember += constStaticDataMember; // OK, the members are static
  // nonStaticDataMember += 1; // <- cannot use/access a non-static member
  staticMemberFunction2(); // OK, staticMemberFunction2 is also static
}

void StaticMembersDemo::nonStaticMemberFunction()
{
  cout << "nonStaticMemberFunction()..." << endl;
  this->nonStaticDataMember++; // OK, nonStaticDataMember is non-static
  nonStaticDataMember++;       // "this" pointer is, of course, optional
  /*
   *  OK: non-static function can access static members
   *  OK: "this: is available in non-static member functions
   */
  this->staticDataMember++;
}

//Note that the singleton (design) pattern is used here
class Logger
{
public:
  static Logger& getInstance()
  {
    static Logger theInstance;
    return theInstance;
  }

  void logMsg(const char* msg){
    msgs_.emplace_back(msg);
  }
  void logMsg(const char* fileName, const char* msg){
    std::string message = std::string(fileName) + ": " + msg;
    msgs_.emplace_back(msg);
  }
  void printAll(){
    for(const auto& msg: msgs_){
      std::cout<<msg<<std::endl;
    }
  }

  Logger(const Logger &) = delete;
  Logger& operator=(const Logger &) = delete;

private:
  std::vector<std::string> msgs_;
  Logger() {} // private constructor
};

int main()
{
  StaticMembersDemo::staticMemberFunction1(); // OK, static/class member
  // cannot call a non-static member function without an object argument!
  // StaticMembersDemo::nonStaticMemberFunction();
  StaticMembersDemo smd;
  smd.staticMemberFunction2();   // OK
  smd.nonStaticMemberFunction(); // OK
  ClassThatCountsItsInstances class1;
  ClassThatCountsItsInstances class2;

  Logger &logger = Logger::getInstance();
  logger.logMsg(__FILE__, "File does not exist");
  //...
  logger.logMsg(__FILE__, "Load balancer is not responding");
  //...
  logger.printAll();
  return 0;
}