#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

//Assumptions:
//complex numbers cannot both be zero. Else return zero
//cannot show both +- sign before imaginary 
//if imaginary is 1 then just return "i"
//if real or imaginary are 0 return the one that is not 0

class complex {                           

public:
  friend ostream& operator<<(ostream&, const complex&);
  friend istream& operator>>(istream&, complex&);
  complex(double = 0, double = 0);
  double getReal() const;
  double getImaginary() const;
  void setReal(double re);
  void setImag(double im);
  complex operator+(const complex&) const; 
  complex operator-(const complex&) const;
  complex operator*(const complex&) const;
  complex operator/(const complex&) const;
  complex conjugate() const;
  bool operator==(const complex&) const;
  bool operator!=(const complex&) const;
  complex& operator+=(const complex);
  complex& operator-=(const complex);
  complex& operator*=(const complex comp);
  complex& operator/=(const complex comp);

private:
  double real;
  double imaginary;
};
#endif