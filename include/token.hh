// clase token
#ifndef TOKEN_HH
#define TOKEN_HH

#include <string>

using namespace std;

enum class TokenType {
  TOKEN_TYPE_UNKNOWN,
  TOKEN_TYPE_NUMBER,
  TOKEN_TYPE_OPERATOR,
  TOKEN_TYPE_PARENTHESIS,
  TOKEN_TYPE_END
};

class Token {
public:
  Token(TokenType type, string value);
  TokenType type();
  string getValue();
  double getNumber();
  bool isNumber();
  bool isOperator();
  bool isParenthesisRight();
  bool isParenthesisLeft();

private:
  TokenType tokenType;
  string value;
  double numberValue;
};

#endif