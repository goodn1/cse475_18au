#include "Active3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Active3::_localWeights[];

//int8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 4, 1, 6, -2, -3, 1 };

uint8_t Active3::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Active3::loop(uint32_t dt) {
  Midi::setSound(0x19); // melodics
  Neopixel::setLight(0x05); // melodic
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 0.001f;
}
