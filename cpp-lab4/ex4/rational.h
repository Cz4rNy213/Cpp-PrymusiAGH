#include <iostream>
#include <algorithm> 
#include <numeric>

class Rational
{
public:
  Rational(int numerator, int denominator = 1) : numer{numerator}, denom{denominator} {};
  ~Rational(){}
  Rational(const Rational& copy) : numer{copy.numer}, denom{copy.denom} {};

  Rational& operator=(const Rational& other){
    if(&other != this){
        this->numer = other.numer;
        this->denom = other.denom;
    }
    return *this;
  }
  Rational& operator=(int i){
    if(i!= (this->numer / this->denom)){
        this->numer = i;
        this->denom = 1;
    }
    return *this;
  }

  int numerator() const { return numer; }
  int denominator() const { return denom; }

  static Rational normalize(const Rational& other){
    int gcd_val = std::__gcd(std::abs(other.numer), other.denom);
    int sign = (other.numer < 0) ? -1 : 1;
    return Rational(sign * other.numer / gcd_val, other.denom / gcd_val);
  }
  static Rational normalized(int numerator, int denominator){
    int gcd_val = std::__gcd(std::abs(numerator), denominator);
    int sign = (numerator < 0) ? -1 : 1;
    return Rational(sign * numerator / gcd_val, denominator / gcd_val);
  }

  Rational operator+(const Rational& other) const{
    int common_deno = lcm(this->denom, other.denom);
    int new_num = this->numer * (common_deno / this->denom) + other.numer * (common_deno / other.denom);
    Rational ret(new_num, common_deno);
    return Rational::normalize(ret);
  }
  
  Rational operator-(const Rational& other) const{
    int common_deno = lcm(this->denom, other.denom);
    int new_num = this->numer * (common_deno / this->denom) - other.numer * (common_deno / other.denom);
    Rational ret(new_num, common_deno);
    return Rational::normalize(ret);
  }

  Rational operator*(const Rational& other) const{
  Rational* times = new Rational(0);
  times->numer = this->numer * other.numer;
  times->denom = this->denom * other.denom;
  return *times;
  }
  
  Rational operator/(const Rational& other) const{
  Rational* divide = new Rational(0);
  divide->numer = this->numer * other.denom;
  divide->denom = this->denom * other.numer;
  return *divide;    
  }

  Rational operator+() const{
    return *this;
  }

  Rational operator-() const{
    return Rational(-this->numer, this->denom);
  }

  bool operator==(const Rational& other) const{
    return ((this->numer / this->denom) == (other.numer / other.denom));
  }

  bool operator>=(const Rational& other) const{
    return ((this->numer / this->denom) >= (other.numer / other.denom));
  }

  bool operator<=(const Rational& other) const{
    return ((this->numer / this->denom) <= (other.numer / other.denom));
  }

  bool operator>(const Rational& other) const{
    return ((this->numer / this->denom) > (other.numer / other.denom));
  }

  bool operator<(const Rational& other) const{
    return ((this->numer / this->denom) < (other.numer / other.denom));
  }

private:
  int numer;
  int denom;
  
  int lcm(int a, int b)const{
    return std::abs(a * b) / std::__gcd(a, b);
  }

  void initialize(int numerator, int denominator){
    this->numer = numerator;
    this->denom = denominator;
  }

  friend std::ostream& operator<<(std::ostream &, const Rational &);
  friend std::istream& operator>>(std::istream &, Rational &);
  friend Rational operator+(const Rational&, int);
  friend Rational operator+(int , const Rational&);
  friend Rational operator-(const Rational& , int );
  friend Rational operator-(int , const Rational& );
  friend Rational operator*(const Rational& , int );
  friend Rational operator*(int , const Rational& );
  friend Rational operator/(const Rational& , int );
  friend Rational operator/(int , const Rational& );
};

Rational operator+(const Rational& r, int i){
    Rational* op = new Rational(0);
    op->numer = r.numer + i * r.denom;
    op->denom = r.denom;
    return *op;
}
Rational operator+(int i, const Rational& r){
    Rational* op = new Rational(0);
    op->numer = r.numer + i * r.denom;
    op->denom = r.denom;
    return *op;
}

Rational operator-(const Rational& r, int i){
    Rational* op = new Rational(0);
    op->numer = r.numer - i * r.denom;
    op->denom = r.denom;
    return *op;
}

Rational operator-(int i, const Rational& r){
    Rational* op = new Rational(0);
    op->numer = r.numer - i * r.denom;
    op->denom = r.denom;
    return *op;
}

Rational operator*(const Rational& r, int i){
    Rational* op = new Rational(0);
    op->numer = r.numer * i;
    op->denom = r.denom;
    return *op;
}

Rational operator*(int i, const Rational& r){
    Rational* op = new Rational(0);
    op->numer = r.numer * i;
    op->denom = r.denom;
    return *op;
}

Rational operator/(const Rational& r, int i){
    Rational* op = new Rational(0);
    op->numer = r.numer;
    op->denom = r.denom * i;
    return *op;
}

Rational operator/(int i, const Rational& r){
    Rational* op = new Rational(0);
    op->numer = r.numer;
    op->denom = r.denom * i;
    return *op;
}

std::ostream& operator<<(std::ostream & os, const Rational & rat){
    os << rat.numer << "/" << rat.denom;
    return os;
}

std::istream& operator>>(std::istream & is, Rational & rat){
    std::cout << "numerator = ";
    is >> rat.numer;

    std::cout << "denominator = ";
    is >> rat.denom;

    return is;
}
