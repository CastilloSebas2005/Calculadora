#include <iostream>
#include <token.hh>

using namespace std;

int main() {
  cout << "Calculadora de Expresiones" << endl;
  Token token(TokenType::TOKEN_TYPE_END, "5");
  cout << "Token: " << token.getValue() << endl;
  TokenType tipo = token.type();
  cout << "TokenType: " << static_cast<int>(tipo) << endl;
  cout << "Es un número: " << token.isNumber() << endl;
  cout << "Es un operador: " << token.isOperator() << endl;
  cout << "Número: " << token.getNumber() << endl;
  return 0;
  
}