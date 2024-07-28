#include "ChargeRateCheck.h"
#include "RangeCheck.h"

// Constants for charge rate thresholds and tolerances
#define CHARGE_RATE_MAX 0.8
#define TOLERANCE_PERCENTAGE 5
#define CHARGE_RATE_WARNING_MAX (CHARGE_RATE_MAX - (CHARGE_RATE_MAX * TOLERANCE_PERCENTAGE / 100))

Status checkChargeRate(float chargeRate) {
    if (checkOutOfRange(chargeRate, 0, CHARGE_RATE_MAX, "Charge Rate out of range!") == ERROR) {
        return ERROR;
    }
    return checkApproachingLimit(chargeRate, 0, CHARGE_RATE_WARNING_MAX, "Warning: Charge Rate approaching limit!");
}
