#ifndef TOKENIZER_HH
#define TOKENIZER_HH

#include <queue>
#include <string>
#include <token.hh>

using namespace std;

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

  //esta función es para descartar operadores raros que no sean ' '
  bool rareOperator(int positionD); 
};

#endif