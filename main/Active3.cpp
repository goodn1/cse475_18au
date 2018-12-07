#include "Active3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Active3::_localWeights[];

uint8_t Active3::getNumRepeats() {
 return rand() % 5 + 2; // 2 - 6 repeats
}

void Active3::loop(uint32_t dt) {
  //Midi::setSound(0x19); // melodics
  uint8_t soundIdx = rand() % 7 + 0x19; // Random number between 0x19-0x1F.  
  Midi::setSound(soundIdx);
  Neopixel::setLight(0x05); // melodic
}

const uint8_t* Active3::getLocalWeights() {
  return this->_localWeights;
}

float Active3::getStartleFactor() {
  return 0.001f;
}
