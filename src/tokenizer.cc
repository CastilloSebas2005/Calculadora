#include <string>
#include <tokenizer.hh>
#include <token.hh>
#include <iostream>

using namespace std;

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

// se retornará el arreglo de tokens
Token* tokenizer::tokenList() { 
  //esto genera una fuga de memoria
  Token *vectorOfTokens[sizeArray]; 
  //Se lee la entrada el usuario
  for(int i = 0; i < inputUser.size(); i++){
      //este es para inicializar la clase Token
      
      string general = "";
      if(inputUser[i] == '+'
       || inputUser[i] == '-'
       || inputUser[i] == '*'
       || inputUser[i] == '/')
       {
          state = "Operacion";
          general += inputUser[i];
          cout << state << endl;
          vectorOfTokens[i] = new Token(TokenType::TOKEN_TYPE_OPERATOR, general);
       }
       
  }
  return *vectorOfTokens;
}