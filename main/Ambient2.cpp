#include "Ambient2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient2::_localWeights[];

//int8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 1, 1, 1, 1, 1, 1 };

uint8_t Ambient2::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient2::loop(uint32_t dt) {
  Midi::setSound(29); //insects/crickets
  Neopixel::setLight(0x06); //insects
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 0.001f;
}
