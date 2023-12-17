#include <iostream>
#include <cmath>
#include <memory>

using std::cout;
using std::endl;

class Vector2D
{
public:
  Vector2D(double x = 0, double y = 0) : x_{x}, y_{y} { // (the member) initializer list
    cout << "...constructor working...";
  }

  Vector2D(const Vector2D &other) {
    cout << "...copy constructor working...";
    this->x_ = other.x_;
    this->y_ = other.y_;
  }

  Vector2D& operator=(const Vector2D &other) {
    cout << "...copy operator= working...";
    // first, check for self-assignment
    if (&other != this) {
      this->x_ = other.x_;
      this->y_ = other.y_;
    }

    return *this;
  }

  ~Vector2D() { cout << "...destructor working..." << endl; }

  double length() const { return sqrt(x_ * x_ + y_ * y_); } // implicitly inline function

private:
  double x_;
  double y_;
};

int main()
{
  cout << "About to execute Vector2D v1{1,2}..." << endl;
  Vector2D v1{1,2};
  cout << endl;

  cout << "About to execute Vector2D v1{3,4}..." << endl;
  Vector2D v2{3,4};
  cout << endl;

  cout << "About to execute cout << v2.length()..." << endl;
  cout << "v2.length() = " << v2.length() << endl;

  cout << "About to execute Vector2D v3{v1}..." << endl;
  Vector2D v3{v1}; // copy constructor: initialise v3 using v1
  cout << endl;

  cout << "About to execute Vector2D v4 = v2..." << endl;
  Vector2D v4 = v2; // as above: initialise v4 using v2
  cout << endl;

  cout << "About to execute Vector2D v5 {}..." << endl;
  Vector2D v5 {}; // initialise using the default constructor
  cout << endl;

  cout << "About to execute v5 = v1..." << endl;
  v5 = v1; // set v5 using (copy) assignment operator
  cout << endl;

  cout << "About to execute Vector2D *pV2D = new Vector2D(10,11)..." << endl;
  Vector2D *pV2D = new Vector2D(10,11);
  cout << endl;

  cout << "About to execute Vector2D *pArrV2D[2] = {new Vector2D...}" << endl;
  Vector2D *pArrV2D = new Vector2D[2];
  cout << endl;

  cout << "About to execute delete pV2D..." << endl;
  /*
   * When using "raw" C++98 pointers,
   * the allocated memory
   * MUST BE released explicitly!
   */
  delete pV2D;
  cout << endl;

  cout << "delete [] pArrV2D" << endl;
  /*
   * You cannot use "delete pArrV2D" below!
   * Remember: new -> delete, new [] -> delete []
   */
  delete [] pArrV2D;
  cout << endl;

  // Note: Smart pointers will be the subject of another lecture
  {
     cout << "About to execute auto uPtr = std::unique_ptr..." << endl;
     auto uPtr = std::unique_ptr<Vector2D>(new Vector2D(10,11));
     cout << endl;
     cout << "About to leave the local scope..." << endl;
     /*
      * When using smart pointers, 
      * memory is released automatically
      * (see the RAII idiom)
      */
  }

  return 0;
}