#ifndef POSTFIJA_HH
#define POSTFIJA_HH

#include <queue>
#include <stack>
#include <string>
#include <token.hh>

class postfija {
public:
  postfija(queue<Token> tokenqueue);
  double getResult();
  string showError();

private:
  string error;
  double result;
  queue<Token> tokenQueue;
};

#endif