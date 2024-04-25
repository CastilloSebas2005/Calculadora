//calculadora postfija//
#ifndef CALPOSTFIJA_HH
#define CALPOSTFIJA_HH

#include <queue>
#include<token.hh>
#include <string>
using namespace std;

class calpostfija{
    public:
        calpostfija(queue<Token *> cola);//falta incluirlo
        double calcular();
        string Error() const;
        bool valido() const;
        double Resultadof() const;
    private: 
        queue<Token *> cola;
        void Evaluarexp();
        string error;
        double resultadof;
        bool valido;

};
#endif