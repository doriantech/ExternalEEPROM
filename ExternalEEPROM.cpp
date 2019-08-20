#include <Arduino.h>
#include <stdint.h>
#include <Wire.h>
#include "ExternalEEPROM.h"

EEProto::EEProto(long index,uint8_t addr,long length) {
  _index = index;
  _addr = addr;
  _length = length;
}

EEProto::operator uint8_t() const {
  uint8_t c;
  uint8_t a = _addr;
  if(_length < 4096) {
    a &= ~(uint_8_t((_length-1) >> 8));
    a |= uint_8_t((_index-1) >> 8);
  }
  Wire.beginTransmission(a);
  if(_length >= 4096) {
    Wire.write(_index >> 8);
  }
  Wire.write(_index & 0xFF);
  Wire.endTransmission();
  Wire.requestFrom(a, 1);
  while (Wire.available()) {
    c = Wire.read();
  }
  return c;
}

void EEProto::operator =(uint8_t in) {
  
  uint8_t a = _addr;
  if(_length < 4096) {
    a &= ~(uint_8_t((_length-1) >> 8));
    a |= uint_8_t((_index-1) >> 8);
  }
  Wire.beginTransmission(a);
  if(_length >= 4096) {
    Wire.write(_index >> 8);
  }
  Wire.write(_index & 0xFF);
  Wire.write(in);
  Wire.endTransmission();
  delay(5);
}

void EEProto::operator +=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) + in;
}
void EEProto::operator -=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) - in;
}
void EEProto::operator *=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) * in;
}
void EEProto::operator /=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) / in;
}
void EEProto::operator ^=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) ^ in;
}
void EEProto::operator %=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) % in;
}
void EEProto::operator &=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) & in;
}
void EEProto::operator |=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) | in;
}
void EEProto::operator <<=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) << in;
}
void EEProto::operator >>=(uint8_t in) {
  EEProto b(_index,_addr);
  b = uint8_t(b) >> in;
}

ExternalEEPROM::ExternalEEPROM(long len, uint8_t addr) {
  _length = len;
  _addr = addr;
  Wire.begin();
}

EEProto ExternalEEPROM::operator[](long index) {
    EEProto a(index,_addr);
    return a;
}

uint8_t ExternalEEPROM::read(long index) {
  EEProto a(index,_addr);
  return uint8_t(a);
}

void ExternalEEPROM::write(long index, uint8_t data) {
  EEProto a(index,_addr);
  a = data;
}

void ExternalEEPROM::update(long index, uint8_t data) {
  EEProto a(index,_addr);
  if(a != data) {
    a = data;
  }
}

long ExternalEEPROM::length() {
  return _length;
}
