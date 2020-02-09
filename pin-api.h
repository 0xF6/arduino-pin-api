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
        #if Support_AVR
        switch (flag) 
        {
            case INPUT:
                if (address < 8) 
                {
                    bitClear(DDRD, address);		
                    bitClear(PORTD, address);
                } 
                else if (address < 14) 
                {
                    bitClear(DDRB, (address - 8));
                    bitClear(PORTB, (address - 8));
                } 
                else if (address < 20) 
                {
                    bitClear(DDRC, (address - 14));
                    bitClear(PORTC, (address - 8));
                }
            return;
            case OUTPUT:
                if (address < 8) {
                    bitSet(DDRD, address);
                    bitClear(PORTD, address);
                } else if (address < 14) {
                    bitSet(DDRB, (address - 8));
                    bitClear(PORTB, (address - 8));
                } else if (address < 20) {
                    bitSet(DDRC, (address - 14));
                    bitClear(PORTC, (address - 8));
                }
            return;
            case INPUT_PULLUP:
                if (address < 8) 
                {
                    bitClear(DDRD, address);
                    bitSet(PORTD, address);
                } 
                else if (address < 14) {
                    bitClear(DDRB, (address - 8));
                    bitSet(PORTB, (address - 8));
                } 
                else if (address < 20) {
                    bitClear(DDRC, (address - 14));
                    bitSet(PORTC, (address - 14));
                }
            return;
        }
        #else
        pinMode(address, flag);
        #endif
    }
    inline _DIGITAL<address> digital() {
        return _DIGITAL<address>();
    }
    inline _ANALOG<address> analog() {
        return _ANALOG<address>();
    }
};
#endif