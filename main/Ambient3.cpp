#include "Ambient3.h"
#include "Debug.h"

constexpr uint8_t Ambient::_localWeights[];

uint8_t Ambient3::getNumRepeats() {
 return rand()%4 + 4;
}

uint8_t Ambient3::getId() {
  return 5;
}

void Ambient3::loop(uint32_t dt) {
  Serial.println(F("Ambient..."));
}

const uint8_t* Ambient3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient3::getStartleFactor() {
  return 9999999999;
}

bool Ambient3::rxStartle(uint8_t len, uint8_t* payload) {}

void Ambient3::PIR() {
  dprintln("PIR triggered!");
}

void Ambient3::startled() {}
