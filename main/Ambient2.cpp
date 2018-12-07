#include "Ambient2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient2::_localWeights[];

uint8_t Ambient2::getNumRepeats() {
 return rand() % 5 + 6; // 6 - 10 repeats
}

void Ambient2::loop(uint32_t dt) {
  //Midi::setSound(29); //insects/crickets
  uint8_t soundIdx = rand() % 2 + 0x29; // Random number between 0x29-0x2A.
  Midi::setSound(soundIdx);
  Neopixel::setLight(0x06); //insects
}

const uint8_t* Ambient2::getLocalWeights() {
  return this->_localWeights;
}

float Ambient2::getStartleFactor() {
  return 0.001f;
}
