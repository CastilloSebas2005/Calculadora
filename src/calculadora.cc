#include <algorithm> // Para transform
#include <calculator.hh>
#include <cctype> // Para tolower
#include <iostream>
#include <queue>
#include <shunting_yard.hh>
#include <string> // Para string
#include <token.hh>
#include <tokenizer.hh>
using namespace std;

int main() {
  bool control;
  while (control) {
    string expression;
    cout << "Ingrese una expresion o escriba salir" << endl;
    getline(cin, expression);
    calculator usuario(expression);
    control = usuario.evaluatorOfExpression();
  }

  return 0;
}