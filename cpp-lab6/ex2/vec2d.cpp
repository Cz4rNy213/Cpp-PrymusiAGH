#include "vec2d.h"

// Vec2D::Vec2D(double x = 0, double y = 0) : x_{x}, y_{y} {}
std::ostream& operator<<(std::ostream& out, const Vec2D& v)
{
  out << "[" << v.x_ << "," << v.y_ << "]";
  return out;
}

std::istream& operator>>(std::istream& in, Vec2D& v)
{
  char c;
  double x, y;

  //    [  1.2    , 12.3    ]
  //    c    x    c    y    c
  in >> c >> x >> c >> y >> c;

  // no error, so we can set the object data (i.e. x_ and y_)
  v.x_ = x;
  v.y_ = y;

  return in;
}
