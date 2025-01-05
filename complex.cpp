#include <iostream>
using namespace std;
#include "complex.h"
#include <cmath>

// ----------------ComplexNumbers--------------------------------------

// Peter Chang CSS 501

// 10/20/21

// Date of Last Modification: 10/21/21

// --------------------------------------------------------------------------------------------------------------------

// Purpose - a brief statement of the program's function 

// Program is designed to tak ein complex numbers and perform calculations with function overloading while adhereing to edge cases. -------------------------------------------------------------------------------------------------------------------- // 

// --------------------------------------------------------------------------------------------------------------------
//constructor: This is initializing the variables real and imaginary
complex::complex(double r, double i)//variables set as double
{  
// Initial values are zero   
    real = r;  
    imaginary = i;  
}
//ostream operator overload
//Description: Purpose of this is to handle edge cases as well as output the results
//Note: I am aware that the way I am currently handling the edge cases is far from efficient. I had to defer to this method of handling each in a separate else if statement b/c I ran out of time. With that said, my code still catches all the edge cases. 
ostream& operator<<(ostream& out, const complex& comp){
    if(comp.real== 0 && comp.imaginary == 0){
    out << 0.0; //if both values are 0 then output should be 0
    }
    else if (comp.real == 0.0 && comp.imaginary == 1.0){
      out << "i"; //output should be just "i" if real == 0 and imaginary == 1.0
    }
    else if (comp.real == 0.0 && comp.imaginary > 0.0){
      out << comp.imaginary << "i"; //when real is zero and imaginary > 0.0 then it should prent with the "i"
    }
    else if (comp.real == 0.0 && comp.imaginary == -1){
      out << "-i"; //handling special cases when imaginary == -1
    }
    else if (comp.real == 0.0 && comp.imaginary < 0.0){
      out << comp.imaginary << "i"; //cases when imaginary is negative it should print imaginary with the "i"
    }
    else if (comp.imaginary == 1.0){
      out << comp.real << "+" << "i"; //drop the imaginary number if imaginary == 1
    }
    else if(comp.real == 0){
      out << comp.imaginary; //return imaginary in cases where real is 0
    }
    else if (comp.imaginary == 0){
      out << comp.real; //return real in cases where imaginary is 0 
    }
    else if (comp.real > 0.0 && comp.imaginary < 0.0){
      out << comp.real << comp.imaginary << "i";
    } //avoids printing something like: x+-yi
    else{
      out << comp.real << "+" << comp.imaginary << "i";
    } //catch-all to print the values as is
    
    return out;
  }
//Description: The purpose of the instream operator is to take in the input from the user. 
istream& operator>>(istream& input, complex& comp) {

    input >> comp.real >> comp.imaginary;
    return input;
}
//getter for real value
double complex::getReal() const{
  return real;
}
//getter for imaginary value
double complex::getImaginary() const{
  return imaginary;
}
//setter for real value
void complex::setReal(double re){
  real = re;

}
//setter for imaginary value
void complex::setImag(double im){
  imaginary = im;
}
//operator overload on + where we add the real + imaginary from both the argument and the class members
complex complex::operator+(const complex& comp)const {
  complex result; //create complex variable called result to return 
  result.real = real + comp.real;
  
  result.imaginary = imaginary + comp.imaginary;
  return result; //return the complex variable
}
//operator overload on - where we subtract the real - imaginary from both the argument and the class members
complex complex::operator-(const complex& comp)const {
  complex result; //create complex variable called result to return 
  result.real = real - comp.real;

  result.imaginary = imaginary - comp.imaginary;
  return result;
}
//operator overload on *
complex complex::operator*(const complex& comp) const {
  complex result; //create complex variable called result to return 
  result.real = (real * comp.real) - (imaginary * comp.imaginary);

  result.imaginary = (real * comp.imaginary) + (imaginary * comp.real);
  return result;
}
//operator overload on /
//Note that this function must take into account divide by zero error. In here I'm choosing to print out an error and also return *this
complex complex::operator/(const complex& comp) const {
  complex result;
  //check if the denominator is == 0
  if((pow(comp.real,2) + pow(comp.imaginary,2)) == 0){
    cout << "ERROR: CANNOT DIVIDE BY ZERO:"<< endl;
    return *this;
  }
  else{
    result.real = ((real * comp.real) + (imaginary * comp.imaginary))/(pow(comp.real,2) + pow(comp.imaginary,2));

    result.imaginary = ((comp.real * imaginary) - (comp.imaginary * real))/(pow(comp.real,2) + pow(comp.imaginary,2));
    return result;
  }

}
//function for conjugate
//this function is just changing the sign for the imaginary value
complex complex::conjugate() const {
  complex conj; 
  conj.imaginary = -1 * imaginary; 
  conj.real = real; 
  return conj;
  }

bool complex::operator==(const complex& comp) const{
  return real == comp.real && imaginary == comp.imaginary;
}

bool complex::operator!=(const complex& comp) const{
  return real != comp.real || imaginary != comp.imaginary;
}

complex& complex::operator+=(const complex comp)
{
    real = real + comp.real;
    imaginary = imaginary + comp.imaginary;

    return *this;
}
//assignment *= function overload
complex& complex::operator-=(const complex comp)
{
    real = real - comp.real;
    imaginary = imaginary - comp.imaginary;

    return *this;
}
//assignment *= function overload
complex& complex::operator*=(const complex comp)
{
    real = (real * comp.real) - (imaginary * comp.imaginary);
    imaginary = (imaginary * comp.real) + (real * comp.imaginary);

    return *this;
}
//assignment /= function overload
complex& complex::operator/=(const complex comp)
{
    real = ((real*comp.real) + (imaginary * comp.imaginary))/(pow(comp.real,2) + pow(comp.imaginary,2));
    imaginary = ((imaginary*comp.real)-(real*comp.imaginary))/(pow(comp.real,2) + pow(comp.imaginary,2));

    return *this;

}






