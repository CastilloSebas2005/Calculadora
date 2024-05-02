#include <algorithm> // Para transform
#include <calculator.hh>
#include <cctype> // Para tolower
#include <iostream>
#include <postfija.hh>
#include <queue>
#include <shunting_yard.hh>
#include <stdexcept>
#include <string>
#include <token.hh>
#include <tokenizer.hh>

calculator::calculator(string input) : inputUser(input) {}

void calculator::printResult(double numberToPrint) {
  cout << "El resultado de su operación es: " << numberToPrint << endl;
}

bool calculator::evaluatorOfExpression() {
  transform(inputUser.begin(), inputUser.end(), inputUser.begin(), ::tolower);
  if (inputUser == "salir") {
    cout << "Saliendo..." << endl;
    return false;
  } else {
    try {
      tokenizer inputUserToTokens(inputUser);
      queue<Token> expressionToTokens = inputUserToTokens.getList();
      shunting_yard convertExpression(expressionToTokens);
      queue<Token> infixNotation = convertExpression.getOutputQueue();
      postfija solveExpression(infixNotation);
      double result = solveExpression.getResult();
      printResult(result);
    } catch (runtime_error &errorExpression) {
      cerr << "Runtime error: " << errorExpression.what() << std::endl;
    }
    return true;
  }
}