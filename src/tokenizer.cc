#include <iostream>
#include <queue> //esta estructura de datos fue tomada de https://cplusplus.com/reference/queue/queue/
#include <string>
#include <token.hh>
#include <tokenizer.hh>

using namespace std;
                                          
tokenizer::tokenizer(string inputuser) : inputUser(inputuser) {

  double safeNumber = 0;
  int position = 0;
  string previousState;
   string general;
  while (position < inputuser.size()) {
   
    if (inputuser[position] == '+' || inputuser[position] == '-' ||
        inputuser[position] == '*' || inputuser[position] == '/' ||
        inputuser[position] == '_' || inputuser[position] == 'v' ||
        inputuser[position] == '^') {
      previousState = state;
      state = "Operation";
      if (state == previousState) {
        cout << "Problema" << endl;
        // esta función fuerza la salida
        exit(1);
      } else {
        general = inputuser[position];
        Token tokencito(TokenType::TOKEN_TYPE_OPERATOR, general);
        cout << "Numero Token? " << tokencito.isNumber() << endl;
        tokenList.push(tokencito);
      }
    } else if (inputuser[position] >= '0' && inputuser[position] <= '9') {
      previousState = state;
      state = "Number";
      safeNumber = inputuser[position] - '0';
      if(state == previousState){
        safeNumber = safeNumber*10+inputUser[position] - '0';
        
      }else{
        general = to_string(safeNumber); 
        Token tokencito(TokenType::TOKEN_TYPE_OPERATOR, general);
        tokenList.push(tokencito);
      }
    }
    position++;
  }
}
void tokenizer::obtenerLista(){
    Token tokenxd = tokenList.front();
    while(!tokenList.empty()){
      cout << tokenxd.getValue() << endl;
      tokenxd = tokenList.front();
      tokenList.pop(); 
    }
}
queue <Token> tokenizer::getList(){
  return tokenList;
}