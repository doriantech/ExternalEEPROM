#include "ExternalEEPROM.h"
ExternalEEPROM::ExternalEEPROM(int z) {
  y = z;
}
int ExternalEEPROM::operator [](int x) {
  return x+y;
}
