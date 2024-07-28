#ifndef RANGE_CHECK_H
#define RANGE_CHECK_H

typedef enum {
    OK,
    WARNING,
    ERROR
} Status;

Status checkOutOfRange(float value, float min, float max, const char* errorMsg);
Status checkApproachingLimit(float value, float warningMin, float warningMax, const char* warningMsg);

#endif // RANGE_CHECK_H
