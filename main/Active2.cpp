#include "Active2.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Active2::_localWeights[];

uint8_t Active2::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Active2::loop(uint32_t dt) {
  //Midi::setSound(0x21); // bells 1
  uint8_t soundIdx = rand() % 4 + 0x21; // Random number between 0x21-0x24.
  Midi::setSound(soundIdx);
  Neopixel::setLight(0x04); // bell
}

const uint8_t* Active2::getLocalWeights() {
  return this->_localWeights;
}

float Active2::getStartleFactor() {
  return 0.001f;
}
