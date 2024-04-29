#include <iostream>
#include <queue> //esta estructura de datos fue tomada de https://cplusplus.com/reference/queue/queue/
#include <stdexcept>
#include <string>
#include <token.hh>
#include <tokenizer.hh>

using namespace std;

tokenizer::tokenizer(string inputuser) : inputUser(inputuser) {
  int position = 0;
  bool validation = true;
  while (position < inputuser.size() && validation) {
    try {
      if (inputUser[position] == '(' || inputUser[position] == ')') {
        state = TokenType::TOKEN_TYPE_PARENTHESIS;
        string saveParenthesis;
        saveParenthesis += inputUser[position];
        Token tokenPush(state, saveParenthesis);
        tokenList.push(tokenPush);
        position++;
      } else {
        position = addNumber(position);
        position = addOperator(position);
        if (state == TokenType::TOKEN_TYPE_UNKNOWN) {
          position++;
        }
      }
    } catch (const std::runtime_error &e) {
      std::cerr << "Se ha capturado una excepción: " << e.what() << '\n';
      validation = false;
    }
  }
}

int tokenizer::addNumber(int positionD) {
  if (inputUser[positionD] >= '0' && inputUser[positionD] <= '9') {
    bool decimal = false;
    double saveNumber = (inputUser[positionD] - '0');
    double countOfDec = 1;
    state = TokenType::TOKEN_TYPE_NUMBER;
    positionD++;
    while ((positionD < inputUser.size() && inputUser[positionD] >= '0' &&
            inputUser[positionD] <= '9') ||
           inputUser[positionD] == '.') {
      if (inputUser[positionD] == '.') {
        if (decimal == true) {
          throw std::runtime_error("Solo puede haber un punto, no existen "
                                   "numeros con dos puntos decimales");
        } else {
          decimal = true;
        }
      } else {
        if (decimal == true) {
          countOfDec = (countOfDec / 10);
          saveNumber = saveNumber + (countOfDec * (inputUser[positionD] - '0'));
        } else {
          saveNumber = saveNumber * 10 + (inputUser[positionD] - '0');
        }
      }
      positionD++;
    }
    string numberSave = to_string(saveNumber);
    Token tokenPush(state, numberSave);
    tokenList.push(tokenPush);

  } else {
    state = TokenType::TOKEN_TYPE_UNKNOWN;
  }
  return positionD;
}

int tokenizer::addOperator(int positionD) {
  string operatorSave;
  state = TokenType::TOKEN_TYPE_OPERATOR;
  bool isOperator = true;
  switch (inputUser[positionD]) {
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
  case '^':
    operatorSave = "^";
    positionD++;
    break;
  case 'V':
    operatorSave = "V";
    throw std::runtime_error("No puede ingresar 'V' ¿quiso decir 'v'?");
    break;
  default:
    isOperator = false;
    break;
  }
  if (isOperator == true) {
    Token tokenPush(state, operatorSave);
    tokenList.push(tokenPush);
  }
  return positionD;
}

queue<Token> tokenizer::getList() { return tokenList; }

void tokenizer::seeList() {
  while (!tokenList.empty()) {
    Token see = tokenList.front();
    cout << see.getValue();
    tokenList.pop();
  }
}
