#include "Active2.h"
#include "Debug.h"

constexpr uint8_t Active2::_localWeights[];

uint8_t Active2::getNumRepeats() {
 return rand()%4 + 4;
}

void Active2::loop(uint32_t dt) {
  //Serial.println(F("Active..."));
}

const uint8_t* Active2::getLocalWeights() {
  return this->_localWeights;
}

float Active2::getStartleFactor() {
  return 0.0001;
}
