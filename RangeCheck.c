#include <stdio.h>
#include "RangeCheck.h"

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
