#include <cmath>
#include <iostream>
#include <postfija.hh>
#include <queue>
#include <stack>
#include <string>
#include <token.hh>

postfija::postfija(queue<Token> tokenqueue) : tokenQueue(tokenqueue) {
  stack<Token> tokenStack;
  double Result = 0;
  string error = " ";
  while (!tokenqueue.empty()) {
    // Mientras no esté vacía
    Token token = tokenqueue.front();
    tokenqueue.pop();
    if (token.isNumber()) {
      // Si es número lo incluyo de una vez
      tokenStack.push(token);
    } else if (token.isOperator()) {
      // Si es operador, encuentro el primer operando y luego el segundo
      Token operand2 = tokenStack.top();
      tokenStack.pop();
      Token operand1 = tokenStack.top();
      tokenStack.pop();
      string operation = token.getValue();
      // se usa operation[0] para poder hacer el switch y comparar como
      // caractéres
      switch (operation[0]) {
      case '+':
        // suma
        Result = operand1.getNumber() + operand2.getNumber();
        break;
      case '-':
        // resta
        Result = operand1.getNumber() - operand2.getNumber();
        break;
      case '*':
        // Multiplicación
        Result = operand1.getNumber() * operand2.getNumber();
        break;
      case '/':
        // División
        if (operand2.getNumber() == 0)
        // excepción de división entre 0
        {
          error = "Dividir entre 0 es indefinido...";
          showError();
          break;
        } else {
          Result = operand1.getNumber() / operand2.getNumber();
          break;
        }
      case '_':
        // Logaritmo
        if (operand1.getNumber() == 0 || operand2.getNumber() == 0)
        // excepción con log de 0
        {
          error = "Logaritmo de 0 es indefinido...";
          showError();
          break;
        } else {
          Result = log(operand1.getNumber()) / log(operand2.getNumber());
          break;
        }

      case '^':
        // Potencia
        Result = pow(operand1.getNumber(), operand2.getNumber());
        break;
      case 'v':
        // Raíz
        if (operand2.getNumber() < 0 && int(operand1.getNumber()) % 2 == 0)
        // excepción con numeros negativos
        {
          error = "No trabajamos con numeros imaginarios...";
          showError();
          break;
        } else {
          Result = pow(operand2.getNumber(), (1 / operand1.getNumber()));
          break;
        }

      default:
        error = "No introdujo operadores válidos...";
        showError();
        break;
      }
      Token saveResult(TokenType::TOKEN_TYPE_NUMBER, to_string(Result));
      tokenStack.push(saveResult);
    }
    if (tokenStack.size() == 1) {
      Token Result = tokenStack.top();
      result = Result.getNumber();
    }
  }
}
string postfija::showError() { return error; }
double postfija::getResult() { return result; }