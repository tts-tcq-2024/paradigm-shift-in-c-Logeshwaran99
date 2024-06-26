#include <stdio.h>
#include <assert.h>

int temperatureCheck(float temperature){
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}
int stateCheck(float soc){
 if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  }
  else {
    return 1;
  }
}
int chargeRateCheck(float chargeRate){
 if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  else{
    return 1;
  }
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
  int temp1 = 0;
  int temp2 = 0;
  int temp3 = 0;
  temp1 = temperatureCheck(temperature);
  temp2 = stateCheck(soc);
  temp3 = chargeRateCheck(chargeRate);
  if( temp1==1 || temp2==1 || temp3==1 ){
    return 1;
  }
  else{
    return 0;
  }
}

int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}