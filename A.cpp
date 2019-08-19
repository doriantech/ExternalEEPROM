#include "A.h"
A::A(int z) {
  y = z;
}
int A::operator [](int x) {
  return x+y;
}
