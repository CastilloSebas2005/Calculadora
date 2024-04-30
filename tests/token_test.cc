#include <gtest/gtest.h>
#include <token.hh>

TEST(TokenTest, TokenNumber) {
  Token token(TokenType::TOKEN_TYPE_NUMBER, "5");
  EXPECT_EQ(token.getValue(), "5");
  EXPECT_TRUE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_EQ(token.getNumber(), 5);
}

TEST(TokenTest, isParenthesesLeft) {
  Token token(TokenType::TOKEN_TYPE_PARENTHESIS, "(");
  EXPECT_EQ(token.getValue(), "(");
  EXPECT_FALSE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_TRUE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}