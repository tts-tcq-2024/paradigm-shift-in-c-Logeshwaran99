#include "StateOfChargeCheck.h"
#include "RangeCheck.h"

// Constants for state of charge thresholds and tolerances
#define SOC_MAX 80
#define SOC_MIN 20
#define TOLERANCE_PERCENTAGE 5
#define SOC_WARNING_MAX (SOC_MAX - (SOC_MAX * TOLERANCE_PERCENTAGE / 100))
#define SOC_WARNING_MIN (SOC_MIN + (SOC_MIN * TOLERANCE_PERCENTAGE / 100))

Status checkStateOfCharge(float soc) {
    if (checkOutOfRange(soc, SOC_MIN, SOC_MAX, "State of Charge out of range!") == ERROR) {
        return ERROR;
    }
    return checkApproachingLimit(soc, SOC_WARNING_MIN, SOC_WARNING_MAX, "Warning: State of Charge approaching limit!");
}
