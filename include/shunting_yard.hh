// clase shunting yard
#ifndef SHUNTING_YARD_HH
#define SHUNTING_YARD_HH

#include <queue>
#include <stack>
#include <string.h>
#include <tokenizer.hh>

class shunting_yard {
public:
  shunting_yard(queue<Token> tokenqueue);
  queue<Token> getOutputQueue();
  void obtenerQueue();

private:
  int parenthesesError(queue<Token> tokenTemp);
  bool asociativeLeft(Token tokenOperator);
  queue<Token> tokenList; 
  queue<Token> output_Queue;
  stack<Token> operation_Stack;
  int getPrecedence(Token tokenOperator);
  void processOperators(Token tokenOperator);
};

#endif