// clase shuntin yard
#ifndef SHUNTIN_YARD_HH
#define SHUNTIN_YARD_HH

#include <queue>
#include <stack>
#include <string.h>
#include <tokenizer.hh>

class shunting_yard {
public:
  shunting_yard(queue <Token> getlist());
  queue <Token> getOutputQueue();
private:
  queue<Token> output_Queue;
  stack<Token> operation_Stack;
};

#endif