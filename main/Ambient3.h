#ifndef _AMBIENT3_H_
#define _AMBIENT3_H_

#include "Creature.h"
#include "State.h"

class Ambient3 : public State {
 public:
  Ambient3(Creature& creature) : State(creature, "Ambient 3", 5) {}
  uint8_t getNumRepeats();
  //State* transition() override;
  void loop(uint32_t dt);
  //uint8_t getId();
  const uint8_t* getLocalWeights();
  float getStartleFactor();
  //bool rxStartle(uint8_t len, uint8_t* payload);
  //void PIR();
  //void startled();
private:
  static constexpr uint8_t _localWeights[ACTIVE_STATES + AMBIENT_STATES] = {1, 5, 1, 2, 1, 3};
};

#endif  // _AMBIENT_H_
