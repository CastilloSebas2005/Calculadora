#include <string>
#include <tokenizer.hh>

tokenizer::tokenizer(string inputuser) : inputUser(inputuser) {
  int sizearray = 0;

  for (int i = 0; i < inputuser.size(); i++) { // obtiene el tamaño sin espacios de el array de tokens
    if (inputuser[i] != ' ') {
      sizearray += 1; // tamaño del input sin espacios, esto para asignarle un
                      // tamaño adecuado al arreglo de tokens que se retornará
    }
  }

  sizeArray = sizearray;
}

int tokenizer::getSizeArray() { return sizeArray; }

Token* tokenizer:: tokenList(){
    Token* vectorOfTokens[20];
}