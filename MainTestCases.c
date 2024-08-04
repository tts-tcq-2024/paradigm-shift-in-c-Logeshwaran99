#include <assert.h>
#include <stdio.h>
#include "BatteryManagementSystem.h"

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
