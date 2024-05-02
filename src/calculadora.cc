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
  string expresionIni;
  
  do{
    cout << "Ingrese una expresion"<< endl;
    calculator();
    cout << "¿Quiere hacer otra expresion?"<<endl;
    cout << "Si no, escriba 'salir' "<<endl;
    cin>>expresionIni;
    transform(expresionIni.begin(), expresionIni.end(), expresionIni.begin(), ::tolower);

  }while(expresionIni != "salir");
  
  return 0;
}