//
// Created by 2ToThe10th on 28.12.2019.
//

#ifndef GAME_POSITION_H
#define GAME_POSITION_H
#include "Rule.h"

class Position {
public:
  Rule* rule;
  int position;
  int start;

  Position() = default;
  Position(Rule* rule, int position, int start): rule(rule), position(position), start(start) {}

  bool operator== (Position& other) {
    return rule == other.rule && position == other.position && start == other.start;
  }
};

#endif // GAME_POSITION_H
