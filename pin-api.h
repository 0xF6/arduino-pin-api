// /0xF6/arduino-pin-api
// Copyright Yuuki Wesp 2020
// MIT License
#pragma once
#ifndef __PIN_API__
#define __PIN_API__
#include "Arduino.h"
#define __PIN_API_VERSION__ /* yymmdd */ 200302
template<unsigned char address>
class _DIGITAL {
    public:
        inline void write(unsigned char value) {
            digitalWrite(address, value);
        }
        inline int read() {
            return digitalRead(address);
        }
};
template<unsigned char address>
class _ANALOG {
    public:
        inline int read() {
            return analogRead(address);
        }
        inline void write(int value) {
            analogWrite(address, value);
        }
};
template<unsigned char address>
class pin {
  public:
    inline void mode(unsigned char flag) {
      pinMode(address, flag);
    }
    inline _DIGITAL<address> digital() {
        return _DIGITAL<address>();
    }
    inline _ANALOG<address> analog() {
        return _ANALOG<address>();
    }
};
#endif