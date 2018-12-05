#include "Ambient1.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient1::_localWeights[];

//int8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { -2, -3, -1, -5, -6, -1 };

uint8_t Ambient1::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient1::loop(uint32_t dt) {
  Midi::setSound(0x13); // weather/rain
  Neopixel::setLight(0x0F); // rain cycle
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.001f;
}
