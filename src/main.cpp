//
// Created by 2ToThe10th on 28.12.2019.
//
#ifdef DEBUG
#include <gtest/gtest.h>
#endif
#include "EarleyParser.h"
#include <iostream>

int main() {

#ifdef DEBUG
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
#endif

  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");
  rules.emplace_back('A', "aAbA");

  parser->ReadRules(rules);

  std::string str;
  std::cin >> str;
  std::cout << parser->CheckWord(str) << std::endl;

  return 0;
}
