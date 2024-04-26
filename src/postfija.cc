#include<shunting_yard.hh>
#include <stack>
#include <queue>
#include<token.hh>
#include <string>
#include<postfija.hh>
using namespace std;

calpostfija::calpostfija(shunting_yard output_queue):output_Queue(output_queue){//implementación de la calcu//

    cola=output_Queue.getOutputQueue();

}
void calpostfija::Evaluarexp(){
    stack<double> pila;
    while (!cola.empty())
    {
        Token token= cola.front();
        cola.pop();
        if (token.isNumber())
        {
            pila.push(token.getNumber());
        }
        else if(token.isOperator()) {

        }
        
    }
    
}