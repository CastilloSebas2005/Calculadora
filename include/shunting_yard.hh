// clase shuntin yard
#ifndef SHUNTIN_YARD_HH
#define SHUNTIN_YARD_HH

#include <queue>
#include <stack>
#include <string.h>
#include <tokenizer.hh>

class shunting_yard {
public:
  shunting_yard(tokenizer tokenlist);
  queue <Token> getOutputQueue();
private:
  tokenizer tokenList;
  queue<Token> tokenQueue; //cola que recibe la lista de tokens del tokenizer
  queue<Token> output_Queue;
  stack<Token> operation_Stack;
};

#endif