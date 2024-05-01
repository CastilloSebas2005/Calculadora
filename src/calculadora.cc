#include <iostream>
#include <token.hh>
#include <tokenizer.hh>
#include <shunting_yard.hh>
#include <queue>
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
  tokenizer prueba(") 5 + 1 ( 8 + }{5+1)(");
  queue <Token> pruebaT = prueba.getList();
  shunting_yard prueba2(pruebaT);
  prueba2.obtenerQueue();
  return 0;
}