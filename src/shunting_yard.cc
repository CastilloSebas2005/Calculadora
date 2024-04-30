#include <iostream>
#include <queue>
#include <shunting_yard.hh>
#include <string>
#include <token.hh>
#include <tokenizer.hh>

using namespace std;

shunting_yard::shunting_yard(queue<Token> tokenlist) : tokenList(tokenlist) {
  // El shunting yard se hara mientras haya tokens que leer del tokenQueue
  while (!tokenlist.empty()) {
    Token token = tokenlist.front();
    // Si el token es un numero, se va a la cola de salida
    if (token.isNumber()) {
      output_Queue.push(token);
      // cout << "Leyendo:" << token.getNumber() << endl;
    }
    // si el token es un operador, se hace el siguiente caso
    if (token.isOperator()) {
      /*Mientras el stack de operadores no este vacio, el principio del stack
      no sea un parentesis izq y el token del stack de operadores tenga mayor
      precedencia que la del token de la lista de tokens o sean de misma
      precedencia, entonces los operadores que estaban en el stack de
      operadores, se van a pasar a la cola de salida, por ultimo el token con
      menor precedencia se pasara al stack de operaciones*/
      processOperators(token);
      operation_Stack.push(token);
    }
    // si el token es un parentesis izquierdo, se pasara al stack de
    // operaciones
    if (token.isParenthesesLeft()) {
      operation_Stack.push(token);
    }
    // si el token es un parentesis derecho, se hara el siguiente caso
    if (token.isParenthesesRight()) {
      /*Mientras el stack de operaciones no este vacio y el primer operador
      del mismo no sea un parentesis izquierdo,anada a la cola de salida, el
      primer operador del stack de operaciones
      */
      while (!operation_Stack.empty() &&
             !operation_Stack.top().isParenthesesLeft()) {
        output_Queue.push(operation_Stack.top());
        operation_Stack.pop();
      }
      // Si el stack esta vacio, cuando el token entra al condicional de si es
      // parentesis derecho, significa que no hay uno o mas parentesis
      // izquierdos
      if (operation_Stack.empty()) {
        cout << "Error, falta un parentesis izquierdo" << endl;
      }
      // si el operador es un parentesis izquierdo, se elimina del stack de
      // operaciones
      if (!operation_Stack.empty() &&
          operation_Stack.top().isParenthesesLeft()) {
        operation_Stack.pop();
      }
    }
    tokenlist.pop();
  }
  /*Aparte, si quedan operadores en el stack de operaciones y el primer
  operador no es un parentesis izquierdo, el operador que este de primero en
  el stack, se anadira en el token de salida*/
  while (!operation_Stack.empty() &&
         !operation_Stack.top().isParenthesesLeft()) {
    output_Queue.push(operation_Stack.top());
    operation_Stack.pop();
  }
  // si al final, al revisar la cima del stack se encontro un parentesis
  // izquierdo, significa que no hay no hay uno o mas parentesis derechos, ya
  // que el izquierdo quedo guardado en el stack y el programa nunca entro al
  // condicional de si el token a revisar era un parentesis derecho
  if (operation_Stack.top().isParenthesesLeft()) {
    cout << "Error, falta un parentesis derecho" << endl;
  }
}

// Eliminar al final
void shunting_yard::obtenerQueue() {
  while (!output_Queue.empty()) {
    Token token = output_Queue.front();
    cout << token.getValue() << ", ";
    output_Queue.pop();
  }
  cout << endl;
}

// Metodo que le da la precedencia a los operadores
int shunting_yard::getPrecedence(Token tokenOperator) {
  string tokenOp = tokenOperator.getValue();
  if (tokenOp == "^" || tokenOp == "_" || tokenOp == "v") {
    return 3;
  } else if (tokenOp == "*" || tokenOp == "/") {
    return 2;
  } else if (tokenOp == "+" || tokenOp == "-") {
    return 1;
  }
  return 0;
}
// metodo que hace el caso de si el token es un operador
void shunting_yard::processOperators(Token tokenOperator) {
  while (
      !operation_Stack.empty() &&
      (!operation_Stack.top().isParenthesesLeft()) &&
      (getPrecedence(operation_Stack.top()) >= getPrecedence(tokenOperator)) &&
      asociativeLeft(tokenOperator)) {
    output_Queue.push(operation_Stack.top());
    operation_Stack.pop();
  }
}

// Metodo que decide si el operador a analizar es un izquierdo asociativo
bool shunting_yard::asociativeLeft(Token tokenOperator) {
  if (tokenOperator.getValue() == "+" || tokenOperator.getValue() == "-" ||
      tokenOperator.getValue() == "*" || tokenOperator.getValue() == "/") {
    return true;
  } else {
    return false;
  }
}

// Metodo que devuelve la cola hacia la clase que se necesite, en este caso
// hacia la clase calc post fija
queue<Token> shunting_yard::getOutputQueue() { return output_Queue; }