#include <iostream>
#include <fstream>
#include <vector>
#include "vec2d.h"

using namespace std;

// class Vec2D
// {
// public:
//   Vec2D(double x = 0, double y = 0) : x_{x}, y_{y} {}
    
//     void serialiseTo(const char* fileName){
//     ofstream text(fileName);
//     std::srand(1);
//     double x = (rand() % 1000) / 10;
//     double y = (rand() % 1000) / 10;
//     Vec2D v(x, y);
//     text << v << endl;
//     }

//     static Vec2D deserialiseFrom(const char* fileName){
//         Vec2D v;
//         ifstream file(fileName);
//         file >> v;
//         return v;
//     }

// private:
//   double x_;
//   double y_;
//   friend ostream& operator<<(ostream&, const Vec2D&);
//   friend istream& operator>>(istream&, Vec2D&);
// };

// ostream& operator<<(ostream& out, const Vec2D& v)
// {
//   out << "[" << v.x_ << "," << v.y_ << "]";
//   return out;
// }

// istream& operator>>(istream& in, Vec2D& v)
// {
//   char c;
//   double x, y;

//   //    [  1.2    , 12.3    ]
//   //    c    x    c    y    c
//   in >> c >> x >> c >> y >> c;

//   // no error, so we can set the object data (i.e. x_ and y_)
//   v.x_ = x;
//   v.y_ = y;

//   return in;
// }

void serialiseIntoTxtFileDemo(const char* fileName, const vector<Vec2D>& vecOfV2D)
{
  ofstream out(fileName);
  if (!out) {
    cout << "Cannot open file " << fileName << endl;
    return;
  }

  for (auto v : vecOfV2D) {
    out << v << endl;
  }

  out.close();
}

void deserialiseFromTxtFileDemo(const char* fileName, vector<Vec2D>& vecOfV2D)
{
  ifstream in(fileName);
  if (!in) {
    cout << "Cannot open file " << fileName << endl;
    return;
  }

  Vec2D v;
  while (in >> v) {
    vecOfV2D.emplace_back(v);
  }

  in.close();
}

void vectorGenerator(const char* file, int num_of_instances){
    ofstream text(file);
    std::srand(1);
    for(int i = 0; i < num_of_instances; i++){
        double x = (rand() % 1000) / 10;
        double y = (rand() % 1000) / 10;
        Vec2D v(x, y);
        text << v << endl;
    }
    text.close();
}

int main()
{
  const char* fName = "vec2D.txt";
  vector<Vec2D> vecOfV2D1 {
    Vec2D{1.2, 2.3},
    Vec2D{1.23, 4.56},
    Vec2D{12.345, 67.890}
  };

  vector<Vec2D> vecOfV2D2;
  serialiseIntoTxtFileDemo(fName, vecOfV2D1);
  deserialiseFromTxtFileDemo(fName, vecOfV2D2);

  for (auto v : vecOfV2D2) {
    cout << v << endl;
  }

  Vec2D v1{12.34, 567.89};
  v1.serialiseTo("v1.txt");

  Vec2D v2 = Vec2D::deserialiseFrom("v1.txt");
  cout << v2 << endl;
  return 0;
}
