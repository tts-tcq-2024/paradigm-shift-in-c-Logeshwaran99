#include <stdio.h>
#include <assert.h>
#include <BatteryManagementSystem.h>

Status checkOutOfRange(float value, float min, float max, const char* errorMsg) {
    if (value < min || value > max) {
        printf("%s\n", errorMsg);
        return ERROR;
    }
    return OK;
}
Status checkApproachingLimit(float value, float warningMin, float warningMax, const char* warningMsg) {
    if (value < warningMin || value > warningMax) {
        printf("%s\n", warningMsg);
        return WARNING;
    }
    return OK;
}
Status checkTemperature(float temperature) {
    if (checkOutOfRange(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX, "Temperature out of range!") == ERROR) {
        return ERROR;
    }
    return checkApproachingLimit(temperature, TEMPERATURE_WARNING_MIN, TEMPERATURE_WARNING_MAX, "Warning: Temperature approaching limit!");
}
Status checkStateOfCharge(float soc) {
    if (checkOutOfRange(soc, SOC_MIN, SOC_MAX, "State of Charge out of range!") == ERROR) {
        return ERROR;
    }
    return checkApproachingLimit(soc, SOC_WARNING_MIN, SOC_WARNING_MAX, "Warning: State of Charge approaching limit!");
}
Status checkChargeRate(float chargeRate) {
    if (checkOutOfRange(chargeRate, 0, CHARGE_RATE_MAX, "Charge Rate out of range!") == ERROR) {
        return ERROR;
    }
    return checkApproachingLimit(chargeRate, 0, CHARGE_RATE_WARNING_MAX, "Warning: Charge Rate approaching limit!");
}
bool batteryIsOk(float temperature, float soc, float chargeRate) {
    Status tempStatus = checkTemperature(temperature);
    Status socStatus = checkStateOfCharge(soc);
    Status chargeRateStatus = checkChargeRate(chargeRate);
    
    return tempStatus != ERROR && socStatus != ERROR && chargeRateStatus != ERROR;
}
int main() {
   assert(batteryIsOk(25, 70, 0.7));
    return 0;
}
