#include "Active1.h"
#include "Debug.h"
// active1 is the only one that works - follow template for everything else!!!!
constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
 return rand()%4 + 4;
}

void Active1::loop(uint32_t dt) {
  //Serial.println(F("Active..."));
  
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 0.0001;
}
