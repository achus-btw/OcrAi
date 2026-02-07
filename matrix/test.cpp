#include "matrix.hpp"
#include <iostream>

int main() {
  mat m = mat(3, 2);

  mat p = mat(2, 3);
  std::cout << "is a man... what has he got " << std::endl;
  m.set(0, 0, 10);
  m.set(0, 1, 11);
  m.set(1, 0, 20);
  m.set(1, 1, 21);
  m.set(2, 0, 30);
  m.set(2, 1, 31);
  m.print();
  p.zero();
  p.set(0, 0, 1);
  p.set(0, 1, 2);
  p.set(0, 2, 3);
  p.set(1, 0, 4);
  p.set(1, 1, 5);
  p.set(1, 2, 6);
  p.print();
  (multiply(p, m)).print();

  return 0;
}
