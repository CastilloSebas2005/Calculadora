#include <string>
#include <token.hh>
#include <queue>

class tokenizer {
public:
  tokenizer(string inputuser);
  void obtenerLista();
  queue <Token> getList();
private:
  string state;
  string inputUser;
  queue <Token> tokenList;
  static bool isOperator(string stateOfToken, int positionOfToken); //estas funcionalidades son diferentes a la de token porque estás tienen que recibir el estado del operador
  static bool isNumber(string stateOfToken, int positionOfToken);
};