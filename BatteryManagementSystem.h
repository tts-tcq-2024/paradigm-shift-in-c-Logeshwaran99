#ifndef BATTERY_MANAGEMENT_SYSTEM_H
#define BATTERY_MANAGEMENT_SYSTEM_H

#include <stdbool.h>
#include "RangeCheck.h"
#include "TemperatureCheck.h"
#include "StateOfChargeCheck.h"
#include "ChargeRateCheck.h"

bool batteryIsOk(float temperature, float soc, float chargeRate);

#endif // BATTERY_MANAGEMENT_SYSTEM_H
