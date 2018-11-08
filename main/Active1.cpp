#include "Active1.h"
#include "Debug.h"

constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
 return 255;
}

State* Active1::transition() {
 State::transition();
// return this;
}

uint8_t Active1::getId() {
  return 0;
}

void Active1::loop(uint32_t dt) {
  Serial.println(F("Active..."));
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 9999999999;
}

bool Active1::rxStartle(uint8_t len, uint8_t* payload) {}

void Active1::PIR() {
  dprintln("PIR triggered!");
}

void Active1::startled() {}
