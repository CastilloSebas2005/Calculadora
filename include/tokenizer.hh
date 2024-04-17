#include <string>
#include <token.hh>

class tokenizer {
public:
  tokenizer(string inputuser);
  Token* tokenList();
  int getSizeArray();
  
private:
  int sizeArray; /*tamaño del arreglo de tokens, se calculara recorriendo el
                    input sin contar sus espacios vacíos*/
  string inputUser;
};