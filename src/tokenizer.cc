#include <iostream>
#include <queue> //esta estructura de datos fue tomada de https://cplusplus.com/reference/queue/queue/
#include <string>
#include <token.hh>
#include <tokenizer.hh>

using namespace std;

tokenizer::tokenizer(string inputuser) : inputUser(inputuser) {
  int position = 0;
  
  while (position < inputuser.size()) {
      if(inputUser[position] == '(' || inputUser[position] == ')'){
        string saveThing;
        saveThing += inputUser[position];
        Token tokenPush(TokenType::TOKEN_TYPE_PARENTHESES, saveThing);
        tokenList.push(tokenPush);
        position++;
      }
      position = addNumber(position);
      position = addOperator(position);
    }
  }


void tokenizer::obtenerLista() {
 while (!tokenList.empty()) {
    Token tokenxd = tokenList.front();
    cout << tokenxd.getValue() << endl;
    tokenList.pop();
  }
}

int tokenizer::addNumber(int positionD) {
  if(inputUser[positionD] >= '0' && inputUser[positionD] <= '9'){
    double saveNumber = (inputUser[positionD] - '0');
    state = TokenType::TOKEN_TYPE_NUMBER;
    positionD++;
    while ((positionD < inputUser.size() && inputUser[positionD] >= '0' && inputUser[positionD] <= '9') || inputUser[positionD] == '.') {
      saveNumber = saveNumber*10 + inputUser[positionD]-'0';
      positionD++;
      
    }
      string numberSave = to_string(saveNumber);
      Token tokenPush(state, numberSave);
      tokenList.push(tokenPush);
  }else{
    positionD++;
  }
  return positionD;
}

int tokenizer::addOperator(int positionD){
  string operatorSave;
  state = TokenType::TOKEN_TYPE_OPERATOR;
  bool isOperator = true;
  switch (inputUser[positionD])
  {
    
  case '+':
    operatorSave = "+";
    positionD++;
    break;
  case '-':
    operatorSave = "-";
    positionD++;
    break;
  case '*':
    operatorSave = "*";
    positionD++;
    break;
  case '/':
    operatorSave = "/";
    positionD++;
    break;
  case 'v':
    operatorSave = "v";
    positionD++;
    break;
  case '_':
    operatorSave = "_";
    positionD++;
    break;
  default:
    isOperator = false;
    break;
  }
  if(isOperator == true){
    Token tokenPush(state, operatorSave);
    cout << "guardado"<< endl;
    tokenList.push(tokenPush);
  }
  return positionD;
}
queue<Token> tokenizer::getList() { return tokenList; }