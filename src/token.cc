#include <token.hh>

using namespace std;

// implementacion de la clase Token(revisar archivo token.hh)
Token::Token(TokenType type, string value) : tokenType(type), value(value) {
  if (type == TokenType::TOKEN_TYPE_NUMBER) {
    numberValue = stod(value);
  }
}

// obtiene el type del token
TokenType Token::type() { return tokenType; }

// obtiene el valor en string
string Token::getValue() { return value; }

// obtiene el valor en double
double Token::getNumber() { return numberValue; }

// averigua si es numero
bool Token::isNumber() { return tokenType == TokenType::TOKEN_TYPE_NUMBER; }

// averigua si es operación
bool Token::isOperator() { return tokenType == TokenType::TOKEN_TYPE_OPERATOR; }

// averigua parentesis derecho
bool Token::isParenthesisRight() {
  return tokenType == TokenType::TOKEN_TYPE_PARENTHESIS &&
         (value == ")" || value == "}" || value == "]");
}

// averigua parentesis izquierdo
bool Token::isParenthesisLeft() {
  return tokenType == TokenType::TOKEN_TYPE_PARENTHESIS &&
         (value == "(" || value == "{" || value == "[");
}