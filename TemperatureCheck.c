#include "TemperatureCheck.h"
#include "RangeCheck.h"

// Constants for temperature thresholds and tolerances
#define TEMPERATURE_MAX 45
#define TEMPERATURE_MIN 0
#define TOLERANCE_PERCENTAGE 5
#define TEMPERATURE_WARNING_MAX (TEMPERATURE_MAX - (TEMPERATURE_MAX * TOLERANCE_PERCENTAGE / 100))
#define TEMPERATURE_WARNING_MIN (TEMPERATURE_MIN + (TEMPERATURE_MIN * TOLERANCE_PERCENTAGE / 100))

Status checkTemperature(float temperature) {
    if (checkApproachingLimit(temperature, TEMPERATURE_WARNING_MIN, TEMPERATURE_WARNING_MAX, "Warning: Temperature approaching limit!") == WARNING) {
        return WARNING;
    }
    return checkOutOfRange(temperature, TEMPERATURE_MIN, TEMPERATURE_MAX, "Temperature out of range!");
}
