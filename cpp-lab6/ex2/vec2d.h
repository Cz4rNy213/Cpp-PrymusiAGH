#include <iostream>
#include <fstream>

class Vec2D
{
public:
  Vec2D(double x = 0, double y = 0) : x_{x}, y_{y} {}
    
    void serialiseTo(const char* fileName){
    std::ofstream text(fileName);
    std::srand(1);
    double x = (rand() % 1000) / 10;
    double y = (rand() % 1000) / 10;
    Vec2D v(x, y);
    text << v << std::endl;
    }

    static Vec2D deserialiseFrom(const char* fileName){
        Vec2D v;
        std::ifstream file(fileName);
        file >> v;
        return v;
    }

private:
  double x_;
  double y_;
  friend std::ostream& operator<<(std::ostream&, const Vec2D&);
  friend std::istream& operator>>(std::istream&, Vec2D&);
};