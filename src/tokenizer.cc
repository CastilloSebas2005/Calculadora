#include <iostream>
#include <string>
#include <token.hh>
#include <tokenizer.hh>

using namespace std;

tokenizer::tokenizer(string inputuser) : inputUser(inputuser) {
  int sizearray = 0;
  for (int i = 0; i < inputuser.size(); i++) { 
    if (inputuser[i] >= '0' && inputuser[i] <= '9') {
      sizearray++;
      TokenType number = TokenType::TOKEN_TYPE_NUMBER;
      while (number == TokenType::TOKEN_TYPE_NUMBER) {
        if (inputuser[i] >= '0' && inputuser[i] <= '9') {
          number = TokenType::TOKEN_TYPE_NUMBER;
          i++;
        } else {
          number = TokenType::TOKEN_TYPE_UNKNOWN;
          i--;
        }
      }
    }
    else if(inputuser[i] == '+'
    || inputuser[i] == '-'
    || inputuser[i] == '*'
    || inputuser[i] == '/'
    || inputuser[i] == '_'
    || inputuser[i] == '('
    || inputuser[i] == ')'
    || inputuser[i] == 'v'
    || inputuser[i] == '^'){
      sizearray++;
    }
  }
  sizeArray = sizearray;
}

int tokenizer::getSizeArray() { return sizeArray; }
