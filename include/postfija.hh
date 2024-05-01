#ifndef POSTFIJA_HH
#define POSTFIJA_HH

#include <stack>
#include <queue>
#include<token.hh>
#include <string>

class postfija{
    public:
        postfija(queue <Token> tokenqueue);
        double getResult();
    private:
        double result;
        queue <Token> tokenQueue;

};



#endif