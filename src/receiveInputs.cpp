#include "receiveInputs.h"
#include "SerialTransfer.h"

namespace receiveInputs
{
    SerialTransfer serialTransfer;
    STRUCT inputStruct;

    void init()
    {
        Serial1.begin(115200);
        serialTransfer.begin(Serial1);
    }
    void poll()
    {
        if (serialTransfer.available())
        {
            serialTransfer.rxObj(inputStruct);
        }
    }
}