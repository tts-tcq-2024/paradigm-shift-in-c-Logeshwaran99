#include "BatteryManagementSystem.h"

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    Status tempStatus = checkTemperature(temperature);
    Status socStatus = checkStateOfCharge(soc);
    Status chargeRateStatus = checkChargeRate(chargeRate);
    
    return tempStatus != ERROR && socStatus != ERROR && chargeRateStatus != ERROR;
}
