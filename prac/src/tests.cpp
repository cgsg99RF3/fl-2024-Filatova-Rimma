#include <gtest/gtest.h>

#include "../include/prac1.h"

TEST(Prac, SimpleTest) {
  for (char ch : {'a', 'b', 'c'}) {
    EXPECT_EQ(GetLen(std::string({ch}), ch, 1), 1);
  }
}

TEST(Prac, PlusTest) {
  for (char ch : {'a', 'b', 'c'}) {
    EXPECT_EQ(GetLen(std::string("abc++"), ch, 1), 1);
  }
}

TEST(Prac, StarTest) {
  for (char ch : {'a', 'b', 'c'}) {
    std::string str;
    str.push_back(ch);
    str.push_back('*');
    const size_t MX = 1e2;
    for (size_t i = 0; i < MX; ++i) {
      EXPECT_EQ(GetLen(str, ch, i), i);
    }
  }
}

TEST(Prac, InvalidSymbolTest) {
  std::string invalid = "ae*";
  EXPECT_THROW(GetLen(invalid, 'x', 1), std::invalid_argument);
}

TEST(Prac, InvalidExpressionTest) {
  EXPECT_THROW(GetLen("ab*", 'x', 1), std::invalid_argument);
  EXPECT_THROW(GetLen("*", 'x', 1), std::invalid_argument);
  EXPECT_THROW(GetLen("a.", 'x', 1), std::invalid_argument);
  EXPECT_THROW(GetLen("a+", 'x', 1), std::invalid_argument);
}

TEST(Prac, InfinityTest) {
  EXPECT_GE(GetLen("a", 'x', 1), INF);
}

TEST(Prac, ComplexTest) {
  EXPECT_EQ(GetLen("acb..bab.c.*.ab.ba.+.+*a.", 'b', 2), 4);
}

TEST(Prac, ComplexInfinityTest) {
  EXPECT_GE(GetLen("ab+c.aba.*.bac.+.+*", 'c', 4), INF);
}

