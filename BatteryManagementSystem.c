#include <stdio.h>
#include <assert.h>

// Constants for thresholds and tolerances
#define TEMPERATURE_MAX 45
#define TEMPERATURE_MIN 0
#define SOC_MAX 80
#define SOC_MIN 20
#define CHARGE_RATE_MAX 0.8

#define TOLERANCE_PERCENTAGE 5

#define TEMPERATURE_WARNING_MAX (TEMPERATURE_MAX - (TEMPERATURE_MAX * TOLERANCE_PERCENTAGE / 100))
#define TEMPERATURE_WARNING_MIN (TEMPERATURE_MIN + (TEMPERATURE_MIN * TOLERANCE_PERCENTAGE / 100))
#define SOC_WARNING_MAX (SOC_MAX - (SOC_MAX * TOLERANCE_PERCENTAGE / 100))
#define SOC_WARNING_MIN (SOC_MIN + (SOC_MIN * TOLERANCE_PERCENTAGE / 100))
#define CHARGE_RATE_WARNING_MAX (CHARGE_RATE_MAX - (CHARGE_RATE_MAX * TOLERANCE_PERCENTAGE / 100))

typedef enum {
    OK,
    WARNING,
    ERROR
} Status;

Status checkTemperature(float temperature) {
    if (temperature < TEMPERATURE_MIN || temperature > TEMPERATURE_MAX) {
        printf("Temperature out of range!\n");
        return ERROR;
    }
    if (temperature < TEMPERATURE_WARNING_MIN || temperature > TEMPERATURE_WARNING_MAX) {
        printf("Warning: Temperature approaching limit!\n");
        return WARNING;
    }
    return OK;
}

Status checkStateOfCharge(float soc) {
    if (soc < SOC_MIN || soc > SOC_MAX) {
        printf("State of Charge out of range!\n");
        return ERROR;
    }
    if (soc < SOC_WARNING_MIN || soc > SOC_WARNING_MAX) {
        printf("Warning: State of Charge approaching limit!\n");
        return WARNING;
    }
    return OK;
}

Status checkChargeRate(float chargeRate) {
    if (chargeRate > CHARGE_RATE_MAX) {
        printf("Charge Rate out of range!\n");
        return ERROR;
    }
    if (chargeRate > CHARGE_RATE_WARNING_MAX) {
        printf("Warning: Charge Rate approaching limit!\n");
        return WARNING;
    }
    return OK;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    Status tempStatus = checkTemperature(temperature);
    Status socStatus = checkStateOfCharge(soc);
    Status chargeRateStatus = checkChargeRate(chargeRate);
    
    return tempStatus != ERROR && socStatus != ERROR && chargeRateStatus != ERROR;
}

int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    assert(batteryIsOk(5, 25, 0.7));  // Test cases for warnings
    assert(batteryIsOk(43, 75, 0.75)); // Test cases for warnings
    assert(!batteryIsOk(-1, 25, 0.7)); // Test cases for out of range
    assert(!batteryIsOk(25, 85, 0.7)); // Test cases for out of range
    assert(!batteryIsOk(25, 25, 0.9)); // Test cases for out of range

    return 0;
}
