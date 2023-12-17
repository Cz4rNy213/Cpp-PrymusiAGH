#include <iostream>

using std::cout;
using std::endl;

class BaseClass {
public:
  BaseClass() {} //the default constructor
  BaseClass(int) {} //another constructor
  void publicFunc() const { cout << "publicFunc()" << endl; }

protected:
  void protectedFunc() const { cout << "protectedFunc()" << endl; }

private:
  void privateFunc() const { cout << "privateFunc()" << endl; }

};

class OtherClass
{
public:
  // calling a selected constructor to initialise member `bc_`
  OtherClass() : bc_(3) {}
  void classAccessTest() {
     bc_.publicFunc();

     //NO access to protected members from an unrelated/underived class
     //bc_.protectedFunc();
     //As above, but for private members
     //bc_.privateFunc();
   }
private:
  BaseClass bc_; // composition
};

class DerivedPublicly : public BaseClass
{
public:
  //Calling a selected contructor of the base class
  DerivedPublicly(int i) : BaseClass(i), pOC_{new OtherClass} {}

  //In composition, the lifetime of a part (here `pOC_`) = owner's lifetime
  ~DerivedPublicly() {
     if (pOC_ != nullptr) {
       delete pOC_; // ...we have to call delete
       pOC_ = nullptr;
     }
  }

  void baseClassAccessTest() const {
     cout << "DerivedPublicly::baseClassAccessTest(), calling:" << endl;
     publicFunc();    //full access to public members
     protectedFunc(); //full assess to protected members from the derived class
     //privateFunc(); //NO access to private members from the derived class
  }
private:
   OtherClass *pOC_ = nullptr; // composition
};

class DerivedProtectedly : protected BaseClass
{
public:
  void baseClassAccessTest() const  {
     cout << "DerivedProtectedly::baseClassAccessTest(), calling:" << endl;
     publicFunc();    //full access to public members
     protectedFunc(); //full assess to protected members from the derived class
     //privateFunc(); //NO access to private members from the derived class
  }
};

class DerivedPrivately : private BaseClass
{
public:
  void baseClassAccessTest() const {
     cout << "DerivedPrivately::baseClassAccessTest(), calling:" << endl;
     publicFunc();    //full access to public members
     protectedFunc(); //full assess to protected members from the derived class
     //privateFunc(); //NO access to private members from the derived class
  }
};

class DerivedFromDerivedPublicly : public DerivedPublicly
{
public:
  DerivedFromDerivedPublicly() : DerivedPublicly(10) {}
  void baseClassAccessTest() const {
     cout << "DerivedFromDerivedPublicly::baseClassAccessTest(), calling:" << endl;
     publicFunc();    //full access to public members
     protectedFunc(); //full assess to protected members from the derived class
     //privateFunc(); //NO access to private members from the derived class
  }
};

class DerivedFromDerivedProtectedly : public DerivedProtectedly
{
public:
    void baseClassAccessTest() const {
      cout << "DerivedFromDerivedProtectedly::baseClassAccessTest(), calling:" << endl;
      publicFunc();    //full access to public members
      protectedFunc(); //full assess to protected members from the derived class
      //privateFunc(); //NO access to private members from the derived class
    }
};

class DerivedFromDerivedPrivately : public DerivedPrivately
{
public:
  void baseClassAccessTest() const {
     cout << "DerivedFromDerivedPrivately::baseClassAccessTest(), no calls possible!" << endl;
     //publicFunc();    //NO access to this member because of private inheritance
     //protectedFunc(); //as above
     //privateFunc();   //as above
  }
};

int main()
{
  DerivedPublicly dPub(1);
  dPub.baseClassAccessTest();

  cout << "main: calling dPub.publicFunc()..." << endl;
  dPub.publicFunc();
  //dPub.protectedFunc(); //NO access to protected members
  //dPub.privateFunc();   //NO access to private members
  cout << endl;

  DerivedProtectedly dProt;
  dProt.baseClassAccessTest();

  //NO access the following members because of protected inheritance
  //dProt.publicFunc();
  //dProt.protectedFunc();
  //dProt.privateFunc();
  cout << endl;

  DerivedPrivately dPriv;
  dPriv.baseClassAccessTest();

  //NO access to the following members because of private inheritance
  //dPriv.publicFunc();
  //dPriv.protectedFunc();
  //dPriv.privateFunc();
  cout << endl;

  DerivedFromDerivedPublicly dFromDPub;
  dFromDPub.baseClassAccessTest();

  cout << "main: calling dFromDPub.publicFunc()..." << endl;
  dFromDPub.publicFunc();
  //dFromDPub.protectedFunc(); //NO access to protected members
  //dFromDPub.privateFunc();   //NO access to private members
  cout << endl;

  DerivedFromDerivedProtectedly dFromDProt;
  dFromDProt.baseClassAccessTest();

  //NO access the following members because of protected inheritance
  //dFromDProt.publicFunc(); //it is a pro
  //dFromDProt.protectedFunc();
  //dFromDProt.privateFunc();
  cout << endl;

  DerivedFromDerivedPrivately dFromDPriv;
  dFromDPriv.baseClassAccessTest();

  //NO access the following members because of private inheritance
  //dFromDPriv.publicFunc();
  //dFromDPriv.protectedFunc();
  //dFromDPriv.privateFunc();
  cout << endl;

  return 0;
}