#include <iostream>
#include <token.hh>
#include <tokenizer.hh>
#include <shunting_yard.hh>
#include <queue>
#include <calculator.hh>
#include <algorithm> // Para transform
#include <string>    // Para string
#include <cctype>    // Para tolower
using namespace std;

int main() {
  string expression;
  
  bool control;
  do{
    cout << "Ingrese una expresion o escriba salir"<< endl;
    getline(cin, expression);
    calculator usuario(expression);
    control = usuario.evaluatorOfExpression();
    
  }while(control);
  
  return 0;
}