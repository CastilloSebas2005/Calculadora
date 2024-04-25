//calculadora postfija//
#include <queue>
#include<token.hh>
#include<stack>
#include <string>
using namespace std;
class calcpostfija{
    public:
        calcpostfija(queue<Token> expresion);
        double calcular();
    private: 
        queue<Token> expresionPostfija;
        stack<Token> resultadoExpresion;
};