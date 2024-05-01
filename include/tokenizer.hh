#ifndef TOKENIZER_HH
#define TOKENIZER_HH

#include <queue>
#include <string>
#include <token.hh>

class tokenizer {
public:
  tokenizer(string inputuser);
  queue<Token> getList();
  void seeList();

private:
  TokenType state;
  string inputUser;
  queue<Token> tokenList;

  // estas funcionalidades son diferentes a la de token porque estas tienen que
  // recibir el estado del operador
  int addOperator(int positionD);
  int addNumber(int positionD);
  int addParethesis(int positionD);
};

#endif