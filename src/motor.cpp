#include "motor.h"

MOTOR::MOTOR(int pin, bool invert, int encoderPinA, int encoderPinB, void (*encoderISR)())
{
    this->pin = pin;
    this->encoderPinA = encoderPinA;
    this->encoderPinB = encoderPinB;
    this->encoderCount = 0;
    this->invertMultiplier = invert ? -1 : 1;
    this->encoderISR = encoderISR;
}

MOTOR::MOTOR(int pin, bool invert)
{
    this->pin = pin;
    this->invertMultiplier = invert ? -1 : 1;
    pinMode(pin, OUTPUT);
}

void MOTOR::begin()
{
    pinMode(pin, OUTPUT);
    pinMode(encoderPinA, INPUT);
    pinMode(encoderPinB, INPUT);

    // !! Make sure interrupt is defined in drive_config.h !!
    // Using rising edge gives half the resolution, but half the interrupts.
    // Do not change this without modifying the readEncoder implementation.
    attachInterrupt(digitalPinToInterrupt(encoderPinA), encoderISR, RISING);
}

void MOTOR::setPower(int power)
{

    // invert direction if set
    power *= invertMultiplier;
    analogWrite(pin, power);
}

void MOTOR::setMotorInvert(bool invert)
{
    invertMultiplier = invert ? -1 : 1;
}

long MOTOR::readEncoderCount()
{
    return encoderCount;
}
void MOTOR::readEncoder()
{
    delay(1000);
}

void MOTOR::resetEncoder()
{
    encoderCount = 0;
}
