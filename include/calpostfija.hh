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
        string Error();
        bool Valido();
        double Resultadof();
        void Ver_Result();
    private: 
        queue<Token> cola;
        void Evaluarexp();
        string error;
        double resultadof;
        bool valido;
        shunting_yard output_Queue;


};
#endif