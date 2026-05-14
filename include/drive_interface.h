#pragma once
#include "motor.h"

namespace drive_interface
{

    void initMotors();

    void forward(int power);
    void backward(int power);
}