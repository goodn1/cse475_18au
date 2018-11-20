#include "Ambient1.h"
#include "Debug.h"
#include "Midi.h"

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
 int min = 4;
 int max = 8;
 return rand() % (max-min+1) + min; // 4 - 8 repeats
}

void Ambient1::loop(uint32_t dt) {
//Midi::setSound(4);
  Midi::setSound(18);
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.001f;
}
