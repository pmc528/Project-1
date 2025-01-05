#include <iostream>
#include "Complex.h"
using namespace std;

int main() {
  std::cout << "Hello World!\n";
  Complex complex(1,4);
  Complex complex2(1,5);
  cout << complex * complex2 << endl;
}