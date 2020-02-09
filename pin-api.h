// /0xF6/arduino-pin-api
// Copyright Yuuki Wesp 2020
// MIT License
#pragma once
#ifndef __PIN_API__
#define __PIN_API__
#include "Arduino.h"

#define Support_AVR \
    defined(__AVR_ATmega328P__) || \
    defined(__AVR_ATmega328__) || \
    defined(__AVR_ATmega328PB__)


#define __PIN_API_VERSION__ /* yymmdd */ 201002
template<unsigned char address>
class _DIGITAL {
    public:
        void write(unsigned char value) {
            #if Support_AVR
            this->clearBit(address);
            if (address < 8) 
                bitWrite(PORTD, address, value);
            else if (address < 14)
                bitWrite(PORTB, (address - 8), value);
            else if (address < 20)
                bitWrite(PORTC, (address - 14), value);
            #else
            digitalWrite(address, value);
            #endif
        }
        inline int read() {
            #if Support_AVR
            if (address < 8)
                return bitRead(PIND, address);
            else if (address < 14)
                return bitRead(PINB, address - 8);
            else if (address < 20)
                return bitRead(PINC, address - 14);
            #else
            return digitalRead(address);
            #endif
        }
    protected:
        #if Support_AVR
        void clearBit(uint8_t pin) {
            #define step(caseID, value, bit) case caseID: bitClear(value, bit); break; 
            switch (pin) {			
                step(3 , TCCR2A, COM2B1)
                step(5 , TCCR0A, COM0B1)
                step(6 , TCCR0A, COM0A1)
                step(9 , TCCR1A, COM1A1)
                step(10, TCCR1A, COM1B1)
                step(11, TCCR2A, COM2A1)
            }
            #undef step
        }
        #endif
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