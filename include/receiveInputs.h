#pragma once
#include <Arduino.h>

namespace receiveInputs
{
    void init();
    void poll();

    // data structure to receive

    struct __attribute__((packed)) STRUCT
    {
        bool PSButton;
        bool Share;
        bool Options;
        bool L3;
        bool R3;
        bool Touchpad;
        bool Up;
        bool Down;
        bool Left;
        bool Right;
        bool Cross;
        bool Circle;
        bool Square;
        bool Triangle;
        bool L1;
        bool R1;
        uint16_t GyrX;
        uint16_t GyrY;
        uint16_t GyrZ;
        uint16_t AccX;
        uint16_t AccY;
        uint16_t AccZ;
    };
    extern STRUCT inputStruct;
}