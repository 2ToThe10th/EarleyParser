//
// Created by 2ToThe10th on 28.12.2019.
//

#ifndef GAME_EARLEYPARSER_H
#define GAME_EARLEYPARSER_H
#include "Rule.h"
#include "Position.h"
#include <vector>

class EarleyParser {
private:
  std::vector<Rule> rules_;

  void Complete(std::vector<std::vector<Position>> &D, int current_position,
                bool &is_changed);
  void Predict(std::vector<std::vector<Position>> &D, int current_position,
               bool &is_changed);
  void Scan(std::vector<std::vector<Position>>& D, int current_position, std::string str);
public:
  EarleyParser() = default;

  void ReadRules(const std::vector<Rule>& rules);

  bool CheckWord(std::string& str);
};

#endif // GAME_EARLEYPARSER_H
