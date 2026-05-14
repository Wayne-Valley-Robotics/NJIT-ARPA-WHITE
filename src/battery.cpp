// #include "battery.h"

// // TODO: emancipate from prizm, figure out how to do that hardware-wise

// int batteryCheck()
// {
//     int voltage = prizm.readBatteryVoltage();
//     // "The battery pack is considered discharged when the voltage drops below 12.1 volts."
//     // [depleted at 9v]
//     int batteryWarnLevel = ((voltage < 1310) + (voltage < 1210) + (voltage < 1010) + (voltage < 900));
//     return batteryWarnLevel;
// }