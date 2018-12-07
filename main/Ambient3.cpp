#include "Ambient3.h"
#include "Debug.h"
#include "Midi.h"
#include "Neopixel.h"

constexpr uint8_t Ambient3::_localWeights[];

uint8_t Ambient3::getNumRepeats() {
 return rand() % 5 + 4; // 4 - 8 repeats
}

void Ambient3::loop(uint32_t dt) {
  //Midi::setSound(15); //wind
  uint8_t soundIdx = rand() % 4 + 0x15; // Random number between 0x15-0x18.
  Midi::setSound(soundIdx);
  Neopixel::setLight(0x0A); //wind
}

const uint8_t* Ambient3::getLocalWeights() {
  return this->_localWeights;
}

float Ambient3::getStartleFactor() {
  return 0.001f;
}
