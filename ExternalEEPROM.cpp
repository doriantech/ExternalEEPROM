#include "ExternalEEPROM.h"
#include <Wire.h>
ExternalEEPROM::ExternalEEPROM(int z) {
  y = z;
}
int ExternalEEPROM::operator [](int x) {
  return x+y;
}
