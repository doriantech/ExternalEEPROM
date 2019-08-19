#include <Wire.h>
#ifndef EXTERNAL_EEPROM_H
#define EXTERNAL_EEPROM_H
class ExternalEEPROM {
  public:
    ExternalEEPROM(int z);
    int operator [](int x);
  private:
    int y;
};
#endif
