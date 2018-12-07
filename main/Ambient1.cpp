#include "Ambient1.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient1::_localWeights[];

uint8_t Ambient1::getNumRepeats() {
 return rand() % 5 + 5; // 5 - 9 repeats
}

void Ambient1::loop(uint32_t dt) {
  //Midi::setSound(0x13); // weather/rain
  uint8_t soundIdx = rand() % 2 + 0x13; // Random number between 0x13-0x14.
  Midi::setSound(soundIdx);
  Neopixel::setLight(0x0F); // rain cycle
}

const uint8_t* Ambient1::getLocalWeights() {
  return this->_localWeights;
}

float Ambient1::getStartleFactor() {
  return 0.001f;
}
