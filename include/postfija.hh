#ifndef POSTFIJA_HH
#define POSTFIJA_HH

#include <queue>
#include <stack>
#include <string>
#include <token.hh>

using namespace std;

class postfija {
public:
  postfija(queue<Token> tokenqueue);
  double getResult();
  void showError();

private:
  string error;
  double result;
  queue<Token> tokenQueue;
};

#endif