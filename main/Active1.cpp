#include "Active1.h"
#include "Debug.h"
#include "Midi.h"

constexpr uint8_t Active1::_localWeights[];

uint8_t Active1::getNumRepeats() {
 int min = 4;
 int max = 8;
 return rand() % (max-min+1) + min; // 4 - 8 repeats
}

void Active1::loop(uint32_t dt) {
  Midi::setSound(15);
}

const uint8_t* Active1::getLocalWeights() {
  return this->_localWeights;
}

float Active1::getStartleFactor() {
  return 0.001f;
}
