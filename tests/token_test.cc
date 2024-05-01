#include <gtest/gtest.h>
#include <token.hh>

TEST(TokenTest, number) {
  Token token(TokenType::TOKEN_TYPE_NUMBER, "5");
  EXPECT_EQ(token.getValue(), "5");
  EXPECT_TRUE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_EQ(token.getNumber(), 5);
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, parenthesesLeft1) {
  Token token(TokenType::TOKEN_TYPE_PARENTHESIS, "(");
  EXPECT_EQ(token.getValue(), "(");
  EXPECT_FALSE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_TRUE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, parenthesesRight1) {
  Token token(TokenType::TOKEN_TYPE_PARENTHESIS, ")");
  EXPECT_EQ(token.getValue(), ")");
  EXPECT_FALSE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_TRUE(token.isParenthesisRight());
}

TEST(TokenTest, parenthesesLeft2) {
  Token token(TokenType::TOKEN_TYPE_PARENTHESIS, "{");
  EXPECT_EQ(token.getValue(), "{");
  EXPECT_FALSE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_TRUE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, parenthesesRight2) {
  Token token(TokenType::TOKEN_TYPE_PARENTHESIS, "}");
  EXPECT_EQ(token.getValue(), "}");
  EXPECT_FALSE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_TRUE(token.isParenthesisRight());
}

TEST(TokenTest, parenthesesLeft3) {
  Token token(TokenType::TOKEN_TYPE_PARENTHESIS, "[");
  EXPECT_EQ(token.getValue(), "[");
  EXPECT_FALSE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_TRUE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, parenthesesRight3) {
  Token token(TokenType::TOKEN_TYPE_PARENTHESIS, "]");
  EXPECT_EQ(token.getValue(), "]");
  EXPECT_FALSE(token.isNumber());
  EXPECT_FALSE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_TRUE(token.isParenthesisRight());
}

TEST(TokenTest, operatorSum) {
  Token token(TokenType::TOKEN_TYPE_OPERATOR, "+");
  EXPECT_EQ(token.getValue(), "+");
  EXPECT_FALSE(token.isNumber());
  EXPECT_TRUE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, operatorMult) {
  Token token(TokenType::TOKEN_TYPE_OPERATOR, "*");
  EXPECT_EQ(token.getValue(), "*");
  EXPECT_FALSE(token.isNumber());
  EXPECT_TRUE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, operatorDiv) {
  Token token(TokenType::TOKEN_TYPE_OPERATOR, "/");
  EXPECT_EQ(token.getValue(), "/");
  EXPECT_FALSE(token.isNumber());
  EXPECT_TRUE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, operatorSubs) {
  Token token(TokenType::TOKEN_TYPE_OPERATOR, "-");
  EXPECT_EQ(token.getValue(), "-");
  EXPECT_FALSE(token.isNumber());
  EXPECT_TRUE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, operatorExp) {
  Token token(TokenType::TOKEN_TYPE_OPERATOR, "^");
  EXPECT_EQ(token.getValue(), "^");
  EXPECT_FALSE(token.isNumber());
  EXPECT_TRUE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}

TEST(TokenTest, operatorLog) {
  Token token(TokenType::TOKEN_TYPE_OPERATOR, "_");
  EXPECT_EQ(token.getValue(), "_");
  EXPECT_FALSE(token.isNumber());
  EXPECT_TRUE(token.isOperator());
  EXPECT_FALSE(token.isParenthesisLeft());
  EXPECT_FALSE(token.isParenthesisRight());
}