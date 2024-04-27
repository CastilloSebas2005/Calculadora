#include <iostream>
#include <token.hh>
#include <tokenizer.hh>
#include <shunting_yard.hh>
using namespace std;

int main() {
  cout << "Calculadora de Expresiones" << endl;
  Token token(TokenType::TOKEN_TYPE_NUMBER, "5");
  cout << "Token: " << token.getValue() << endl;
  TokenType tipo = token.type();
  cout << "TokenType: " << static_cast<int>(tipo) << endl;
  cout << "Es un número: " << token.isNumber() << endl;
  cout << "Es un operador: " << token.isOperator() << endl;
  cout << "Número: " << token.getNumber() << endl;
  tokenizer prueba("3+4*(2/(1-5))^2^3(6/(8*(5+9)))");
  shunting_yard prueba2(prueba);
  prueba2.obtenerQueue();
  return 0;
}