// Header file for the Startle State
// Akhil Avula

#ifndef _STARTLE_H_
#define _STARTLE_H_

#include "Creature.h"
#include "State.h"

class Startle : public State {
 public:
  Startle(Creature& creature) : State(creature, "Startle") {}
  uint8_t getNumRepeats();
  State* transition() override;
  void loop(uint32_t dt);
  uint8_t getId();
  const uint8_t* getLocalWeights();
  float getStartleFactor();
protected:
  bool rxStartle(uint8_t len, uint8_t* payload);
  void PIR();
  void startled();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = { 0 };
};

#endif  // _STARLTE_H_