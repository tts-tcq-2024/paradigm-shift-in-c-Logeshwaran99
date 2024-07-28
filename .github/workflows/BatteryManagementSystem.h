#ifndef BATTERYMANAGEMENTSYSTEM_H
#define BATTERYMANAGEMENTSYSTEM_H


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

Status checkTemperature(float temperature);
Status checkStateOfCharge(float soc);
Status checkChargeRate(float chargeRate);
bool batteryIsOk(float temperature, float soc, float chargeRate);

#endif /*BATTERYMANAGEMENTSYSTEM_H */