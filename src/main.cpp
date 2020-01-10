//
// Created by 2ToThe10th on 28.12.2019.
//
#ifdef DEBUG
#include <gtest/gtest.h>
#endif

#include "EarleyParser.h"
#include <iostream>
#include <string>

int main() {

#ifdef DEBUG
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
#endif

  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  std::string from, to;
  while (true) {
    std::cin >> from;
    std::getline(std::cin, to);
    if (from == "end") {
      break;
    }
    if (!to.empty()) {
      to = to.substr(1, to.size() - 1);
    }
    if (from.size() != 1 || from[0] < 'A' || from[0] > 'Z') {
      std::cout << "Incorrect input: first part of rule might be between A and Z or \"end\", if you finished" << std::endl;
      return 0;
    }
    rules.emplace_back(from[0], to);
  }

//  rules.emplace_back('S', "A");
//  rules.emplace_back('A', "");
//  rules.emplace_back('A', "(A)A");
//  rules.emplace_back('A', "aAbA");

  parser->ReadRules(rules);

  while (true) {
    std::string str;
    getline(std::cin, str);
    if (str == "end") {
      break;
    }
    std::cout << parser->CheckWord(str) << std::endl;
  }

  return 0;
}
