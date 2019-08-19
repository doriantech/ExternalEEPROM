#include <Arduino.h>
#include <stdint.h>
#include <Wire.h>
#ifndef EXTERNALEEPROM_H
#define EXTERNALEEPROM_H
class EEProto {
    public:
      EEProto(long index,uint8_t addr);
      operator uint8_t() const;
      void operator =(uint8_t in);
      void operator +=(uint8_t in);
      void operator -=(uint8_t in);
      void operator *=(uint8_t in);
      void operator /=(uint8_t in);
      void operator ^=(uint8_t in);
      void operator %=(uint8_t in);
      void operator &=(uint8_t in);
      void operator |=(uint8_t in);
      void operator <<=(uint8_t in);
      void operator >>=(uint8_t in);
    private:
      long _index;
      uint8_t _addr;
};


class ExternalEEPROM {
    public:
      ExternalEEPROM(long len, uint8_t addr = 0x50);
      EEProto operator[](long index);
      uint8_t read(long index);
      void write(long index, uint8_t data);
      void update(long index, uint8_t data);
      long length();
    private:
      long _length;
      uint8_t _addr;
};

#define AT24C256 32768L
#define AT24C128 16384L
#define AT24C64 8192L
#define AT24C32 4096L
#define AT24C16 2048L
#define AT24C08 1024L
#define AT24C04 512L
#define AT24C02 256L
#define AT24C01 128L
#endif
