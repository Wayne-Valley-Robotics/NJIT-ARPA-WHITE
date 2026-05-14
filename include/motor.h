#pragma once
#include <Arduino.h>

class MOTOR
{
private:
    uint8_t pin;
    uint8_t invertMultiplier;
    uint8_t encoderPinA;
    uint8_t encoderPinB;
    void (*encoderISR)();
    volatile long encoderCount;
    bool encoderDirection; // true for forward, false for backward

public:
    MOTOR(int pin, bool invert, int encoderPinA, int encoderPinB, void (*encoderISR)());
    MOTOR(int pin, bool invert);
    void begin();
    void setPower(int power);
    void setMotorInvert(bool invert);
    long readEncoderCount();
    void readEncoder();
    void resetEncoder();
};
