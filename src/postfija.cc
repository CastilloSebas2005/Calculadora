#include<shunting_yard.hh>
#include <stack>
#include <queue>
#include<token.hh>
#include <string>
#include<postfija.hh>
#include<math.h>
#include<cmath>
using namespace std;

calpostfija::calpostfija(shunting_yard output_queue):output_Queue(output_queue){//implementación de la calcu//

    cola=output_Queue.getOutputQueue();

}
void calpostfija::Evaluarexp(){//todavía no sé si devuelve el resultado entonces lo dejo en void//
    string suma="+", resta="-";
    string multi="*", div="/";
    string pow="^", loga="_",  sqrt="v";
    string parenizq="(", parendere=")";
    stack<double> pila;
    valido=true;//asumimos que de momento la expresión es válida
    while (!cola.empty()&&valido==true)
    //mientras la cola no esté vacía hay que comprobar si se pueden realizar operaciones//
    {
        Token token= cola.front();
        cola.pop();
        if (token.isNumber())
        //si es número, agregamos de una vez a la pila//
        {
            pila.push(token.getNumber());
        }
        else if(token.isOperator()) {
            //encontramos el primer operador//
            if(pila.size()<2){
                //no puede solo haber un operador en la pila//
                error="Error: los operandos son insuficientes";
                valido=false;
                return;
            }
            double ope2=pila.top(); pila.pop();
            //encontramos el primer operando para la operación y lo sacamos//
            double ope1=pila.top(); pila.pop();
            //encontramos el segundo operando para la operación y lo sacamos//
            double resultado=0;
            if (token.getValue().compare(suma)==0)
            //suma
            {
                resultado=ope1+ope2;
                return;
            }
            else if (token.getValue().compare(resta)==0)
            //resta
            {
                resultado=ope1-ope2;
                return;
            }
            else if (token.getValue().compare(multi)==0)
            //multiplicación
            {
                resultado=ope1*ope2;//no importaría el orden pero igual...
                return;
            }
            else if (token.getValue().compare(div)==0)
            {
                if (ope2==0)
                //no se puede dividir entre 0
                {
                    error="Error: Div por 0 es indefinido...";
                    valido=false;
                    return;
                }
                
            }
            else if (token.getValue().compare(pow)==0)
            //potencia
            {
                resultado= powf64(ope1,ope2);
                return;
            }
            else if (token.getValue().compare(loga)==0)
            //logaritmo
            {
                if (ope1==0)//por propiedades de logaritmo, no existe log de 0
                {
                    error="Error: no existe logaritmo de 0";
                    valido=false;
                    return;
                }
                else
                {
                    resultado=log10f64(ope1)/log10f64(ope2);// El cambio de base hace que el operador 2 sea la base
                }
                
                
            }
            
            
            
            
            




        }
        
    }
    
}