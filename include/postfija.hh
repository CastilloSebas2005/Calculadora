//calculadora postfija//
#include <queue>
#include<token.hh>
#include<stack>
#include <string>
using namespace std;
class calcpostfija{
    private: 
        queue<Token> expresionPostfija;
        stack<Token> resultadoExpresion;
    public:
        calcpostfija(queue<Token> expresion);
        double calcular();
};