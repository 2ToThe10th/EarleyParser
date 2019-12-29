//
// Created by 2ToThe10th on 28.12.2019.
//

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Rule.h"
#include "EarleyParser.h"

TEST(OnlyOneALetter, a) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "a");

  parser->ReadRules(rules);
  std::string str = "a";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(OnlyOneALetter, b) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "a");

  parser->ReadRules(rules);
  std::string str = "b";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(OnlyOneALetter, aaa) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "a");

  parser->ReadRules(rules);
  std::string str = "aaa";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(OnlyOneALetter, Empty) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "a");

  parser->ReadRules(rules);
  std::string str = "";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(OnlyALetters, ALotOfA) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "T");
  rules.emplace_back('T', "aT");
  rules.emplace_back('T', "");

  parser->ReadRules(rules);
  std::string str = "aaaaaaaaaaaaaaaaaaaaaaaaa";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(OnlyALetters, Empty) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "T");
  rules.emplace_back('T', "aT");
  rules.emplace_back('T', "");

  parser->ReadRules(rules);
  std::string str = "";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(OnlyALetters, OneA) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "T");
  rules.emplace_back('T', "aT");
  rules.emplace_back('T', "");

  parser->ReadRules(rules);
  std::string str = "a";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(OnlyALetters, HaveOneB) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "T");
  rules.emplace_back('T', "aT");
  rules.emplace_back('T', "");

  parser->ReadRules(rules);
  std::string str = "aaaaaaaaba";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(CorrectBracketSequence, Correct) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");

  parser->ReadRules(rules);
  std::string str = "(()()())()()()((((()))))";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(CorrectBracketSequence, Wrong) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");

  parser->ReadRules(rules);
  std::string str = "(()()())()()()((((())))))";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(CorrectBracketSequence, Empty) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");

  parser->ReadRules(rules);
  std::string str = "";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(CorrectBracketSequence, SmallCorrect) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");

  parser->ReadRules(rules);
  std::string str = "()";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(TwoCorrectBracketSequence, SmallCorrect) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");
  rules.emplace_back('A', "aAbA");

  parser->ReadRules(rules);
  std::string str = "(ab)";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(TwoCorrectBracketSequence, SmallWrong) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");
  rules.emplace_back('A', "aAbA");

  parser->ReadRules(rules);
  std::string str = "(a)b";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(TwoCorrectBracketSequence, Correct) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");
  rules.emplace_back('A', "aAbA");

  parser->ReadRules(rules);
  std::string str = "(aabbab()(ab))()(((a()()b)))";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(TwoCorrectBracketSequence, Wrong) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "");
  rules.emplace_back('A', "(A)A");
  rules.emplace_back('A', "aAbA");

  parser->ReadRules(rules);
  std::string str = "(aabbab()(ab))(a)(b((a()()b)))";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(Palindromes, Correct) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "aAa");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "bAb");
  rules.emplace_back('A', "b");
  rules.emplace_back('A', "cAc");
  rules.emplace_back('A', "c");
  rules.emplace_back('A', "");


  parser->ReadRules(rules);
  std::string str = "aabbcbbaa";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(Palindromes, Wrong) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "aAa");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "bAb");
  rules.emplace_back('A', "b");
  rules.emplace_back('A', "cAc");
  rules.emplace_back('A', "c");
  rules.emplace_back('A', "");


  parser->ReadRules(rules);
  std::string str = "aabbccbbbaa";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(Palindromes, WithD) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "aAa");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "bAb");
  rules.emplace_back('A', "b");
  rules.emplace_back('A', "cAc");
  rules.emplace_back('A', "c");
  rules.emplace_back('A', "");


  parser->ReadRules(rules);
  std::string str = "aabbdcdbbaa";
  EXPECT_EQ(parser->CheckWord(str), 0);
}

TEST(Palindromes, SecondCorrect) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "aAa");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "bAb");
  rules.emplace_back('A', "b");
  rules.emplace_back('A', "cAc");
  rules.emplace_back('A', "c");
  rules.emplace_back('A', "");


  parser->ReadRules(rules);
  std::string str = "aabbccbbaa";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(Palindromes, Empty) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "aAa");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "bAb");
  rules.emplace_back('A', "b");
  rules.emplace_back('A', "cAc");
  rules.emplace_back('A', "c");
  rules.emplace_back('A', "");


  parser->ReadRules(rules);
  std::string str = "";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(ArithmeticExpressions, One) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "(A)");
  rules.emplace_back('A', "A*A");
  rules.emplace_back('A', "A+A");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "1");
  rules.emplace_back('A', "0");


  parser->ReadRules(rules);
  std::string str = "1";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(ArithmeticExpressions, Correct) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "(A)");
  rules.emplace_back('A', "A*A");
  rules.emplace_back('A', "A+A");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "1");
  rules.emplace_back('A', "0");


  parser->ReadRules(rules);
  std::string str = "a*a*a+1*a+0*(a+a)";
  EXPECT_EQ(parser->CheckWord(str), 1);
}

TEST(ArithmeticExpressions, Wrong) {
  auto parser = new EarleyParser();

  std::vector<Rule> rules;
  rules.emplace_back('S', "A");
  rules.emplace_back('A', "(A)");
  rules.emplace_back('A', "A*A");
  rules.emplace_back('A', "A+A");
  rules.emplace_back('A', "a");
  rules.emplace_back('A', "1");
  rules.emplace_back('A', "0");


  parser->ReadRules(rules);
  std::string str = "a*a*a+1*a+0*(aaa+a)";
  EXPECT_EQ(parser->CheckWord(str), 0);
}