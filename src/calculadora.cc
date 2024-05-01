#include <iostream>
#include <token.hh>
#include <tokenizer.hh>
#include <shunting_yard.hh>
#include <queue>
#include <calpostfija.hh>
#include <postfija.hh>
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
  tokenizer prueba("(2+2)*5");
  queue <Token> pruebaT = prueba.getList();
  shunting_yard prueba2(pruebaT);
  queue <Token> test = prueba2.getOutputQueue();
  prueba2.obtenerQueue();
  postfija postfija(test);
  cout << postfija.getResult()<< endl;
  return 0;
}