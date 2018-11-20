#include "Creature.h"
#include "State.h"
#include "Wait.h"
#include "Active1.h"
#include "Active2.h"
#include "Active3.h"
#include "Ambient1.h"
#include "Ambient2.h"
#include "Ambient3.h"

const double startleFactor = 0.6;
State::State(Creature& creature, char* const name, const uint8_t id) : _creature(creature), _id(id) {
  strncpy(_name, name, MAX_NAME_LEN);
  _name[MAX_NAME_LEN] = 0;
};


char* State::getName() {
  return _name;
}

uint8_t State::getId() {
  return _id;
}

void State::playSound(uint8_t sound_idx) {
  // TODO: implement
}

void State::playEffect(uint8_t effect_idx) {
  // TODO: implement
}

bool State::rxPlaySound(uint8_t len, uint8_t* payload) {
  // TODO: implement
  return true; // temp
}

bool State::rxPlayEffect(uint8_t len, uint8_t* payload) {
  // TODO: implement
  return true; // temp
}

bool State::rxStartle(int8_t rssi, uint8_t len, uint8_t* payload) {
  // TODO: implement
 uint8_t strength = payload[0];
 uint8_t id = payload[1];
 double startleWeight = (double) (_creature.GLOBALS.STARTLE_DECAY - rssi) / _creature.GLOBALS.STARTLE_DECAY;
 double decay = 1 / (1 + exp(-1 * startleWeight)) * startleFactor; 
 if (decay * strength > _creature.GLOBALS.STARTLE_THRESHOLD) {
  // startle
 }
}


void State::txStartle(uint8_t strength, uint8_t id) {
  uint8_t payload[2] = {strength, id};
  _creature.tx((uint8_t)PID_STARTLE, (uint8_t)BROADCAST_ADDR, (uint8_t)2, payload);
  return;
  }


void State::PIR() {
  //TODO: implement
}

void State::startled(uint8_t strength, uint8_t id) {
  //TODO: implement
}


int* State::calProb() {
  // TODO: Implement math to replace this
  int probabilities [7] = {5, 7, 12, 3, 2, 9, 23};
  return probabilities;
}

State* State::getNewState(int stateNum) {
  State* ret;
  switch(stateNum) {
    // TODO: return states to be filled
    case 1:
      // return wait state
      return new Wait(_creature);
      
    case 2:
    // return active1
      return new Active1(_creature);
      
  
    case 3:
      // return active2
      return new Active2(_creature);
      
  
    case 4:
      // return active3
     return new Active3(_creature);
    case 5:
      // return ambient1
      return new Ambient1(_creature);
    case 6:
      // return ambient2
      new Ambient2(_creature);
    case 7:
      // return ambient3
      new Ambient3(_creature);
  }
  return ret;
}


State* State::transition() {
  
  //int probabilities [7];
  //int* probabilitiesPtr = calProb();
  
  //int cumProbabilities 
  int stateNum = 0;
  //int* cumProbabilities = probabilitiesPtr;
  int probabilities [7] = {5, 7, 12, 3, 2, 9, 23};
  int cumProbabilities [7] = {5, 7, 12, 3, 2, 9, 23};
  for (int i = 1; i < sizeof(probabilities)/sizeof(probabilities[0]); i++) {
    cumProbabilities[i] = cumProbabilities[i - 1] + probabilities[i];
  }
  int num = rand() % cumProbabilities[6];
  for (int i = sizeof(cumProbabilities)/sizeof(cumProbabilities[0]) - 1; i >= 0; i--) {
    if (num <= cumProbabilities[i]) {
      stateNum = i;
    }
  }
  return State::getNewState(stateNum);
//  // boundary numbers
//  for (int i = 0; i < cumProbabilities.length(); i++) {
//    if (num == cumProbabilities[i]) {
//      stateNum = i;
//    }
//  }
//  // otherwise round up to the next index
//  for (int i = 0; i < cumProbabilities.length() - 1; i++) {
//    if (num >= cumProbabilities[i] && num <= cumProbabilities[i+1]) {
//      stateNum = i+1;
//    }
//  }
  // TODO: implement
  
}

uint8_t* State::getGlobalWeights() {
  return _globalWeights;
}
