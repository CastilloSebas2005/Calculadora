//calculadora postfija//
#ifndef CALPOSTFIJA_HH
#define CALPOSTFIJA_HH

#include<shunting_yard.hh>
#include <stack>
#include <queue>
#include<token.hh>
#include <string>
using namespace std;

class calpostfija{
    public:
        calpostfija(shunting_yard output_Queue);//falta incluirlo
        double calcular();
        string Error() const;
        bool Valido() const;
        double Resultadof() const;
    private: 
        stack<Token> exprostfija;
        queue<Token> cola;
        void Evaluarexp();
        string error;
        double resultadof;
        bool valido;
        shunting_yard output_Queue;


};
#endif