#include "Ambient3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient3::_localWeights[];

//int8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 2, 1, 5, 7, 3, 2 };

uint8_t Ambient3::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient3::loop(uint32_t dt) {
  Midi::setSound(15); //wind
  Neopixel::setLight(0x0A); //wind
}

const uint8_t* Ambient3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient3::getStartleFactor() {
  return 0.001f;
}
