//
// Created by 2ToThe10th on 28.12.2019.
//
#include <string>

#ifndef EARLEYPARSER_RULE_H
#define EARLEYPARSER_RULE_H

class Rule {
public:
  char from;
  std::string to;

  Rule() = default;

  Rule(char from, const std::string& to): from(from), to(to) {}
};

#endif // EARLEYPARSER_RULES_H
