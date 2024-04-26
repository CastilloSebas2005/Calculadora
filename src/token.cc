#include <token.hh>

using namespace std;

// implementacion de la clase Token(revisar archivo token.hh)
Token::Token(TokenType type, string value) : tokenType(type), value(value) {
  if (type == TokenType::TOKEN_TYPE_NUMBER) {
    numberValue = stod(value);
  }
}

TokenType Token::type() { return tokenType; } // No sé si está bien implementada

string Token::getValue() { return value; } // obtiene el valor en string

double Token::getNumber() { return numberValue; } // obtiene el valor en double

bool Token::isNumber() { // averigua si es numero
  if (tokenType == TokenType::TOKEN_TYPE_NUMBER) {
    return true;
  } else {
    return false;
  }
}

bool Token::isOperator() { // averigua si es operación
  if (tokenType == TokenType::TOKEN_TYPE_OPERATOR) {
    return true;
  } else {
    return false;
  }
}

bool Token::isParenthesesRight(){
  if (tokenType == TokenType::TOKEN_TYPE_PARENTHESES && value == ")") {
    return true;
  } else {
    return false;
  }

}
bool Token::isParenthesesLeft(){
  if (tokenType == TokenType::TOKEN_TYPE_PARENTHESES && value == "(") {
    return true;
  } else {
    return false;
  }
}