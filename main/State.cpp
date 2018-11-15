#include "Creature.h"
#include "State.h"
//#include "Active1.h"


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
  return true; // temp
}

void State::txStartle(uint8_t strength, uint8_t id) {  
  // TODO: implement
  
}

void State::PIR() {
  //TODO: implement
}

void State::startled(uint8_t strength, uint8_t id) {
  //TODO: implement
}

int* State::calProb() {
  // TODO: Implement math to replace this
  int probabilities [7] = [5, 7, 12, 3, 2, 9, 23];
  return probabilities;
}

State* State::getNewState(int stateNum) {
  State* ret;
  switch(stateNum) {
    // TODO: return states to be filled
    case 1:
      // return wait state
      return new Wait(creature);
      
    case 2:
    // return active1
      return new Active1(creature);
      
  
    case 3:
      // return active2
      return new Active2(creature);
      
  
    case 4:
      // return active3
     return new Active3(creature);
    case 5:
      // return ambient1
      return new Ambient1(creature);
    case 6:
      // return ambient2
      new Ambient2(creature);
    case 7:
      // return ambient3
      new Ambient3(creature);
  }
  return ret;
}

State* State::transition() {
  int probabilities [7] = calProb();
  int cumProbabilities [7];
  int stateNum = 0;
  cumProbabilities = probabilities;
  for (int i = 1; i < probabilities.length(); i++) {
    cumProbabilities[i] = cumProbabilities[i - 1] + probabilities[i];
  }
  int num = rand(0,cumProbabilities[6]);
  for (int i = cumProbilities.length() - 1; i >= 0; i--) {
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
