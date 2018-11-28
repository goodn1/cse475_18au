#include "Startle.h"
#include "Debug.h"
//#include "Midi.h"

constexpr uint8_t Startle::_localWeights[];

uint8_t Startle::getNumRepeats() {
 int min = 4;
 int max = 8;
 return rand() % (max-min+1) + min; // 4 - 8 repeats
}

void Startle::loop(uint32_t dt) {
  Midi::setSound(18);
}

const uint8_t* Startle::getLocalWeights() {
  return this->_localWeights;
}

float Startle::getStartleFactor() {
  return 9999999999;
}

bool Startle::rxStartle(uint8_t len, uint8_t* payload) {}

void Startle::PIR() {}

void Startle::startled() {}
