#ifndef TOKENIZER_HH
#define TOKENIZER.HH

#include <string>
#include <token.hh>
#include <queue>

class tokenizer {
public:
  tokenizer(string inputuser);
  void obtenerLista();
  queue <Token> getList();
private:
  TokenType state;
  string inputUser;
  queue <Token> tokenList;
  int addOperator(int positionD); //estas funcionalidades son diferentes a la de token porque estás tienen que recibir el estado del operador
  int addNumber(int positionD);
};

#endif