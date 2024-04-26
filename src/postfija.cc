#include<shunting_yard.hh>
#include <stack>
#include <queue>
#include<token.hh>
#include <string>
#include<postfija.hh>
#include<math.h>
#include<cmath>
#include<iostream>
using namespace std;

calpostfija::calpostfija(shunting_yard output_queue):output_Queue(output_queue){//implementación de la calcu//
    cola=output_Queue.getOutputQueue(),
    resultadof=(0), 
    valido=true,
    error=("");
    Evaluarexp();
}
double calpostfija::Resultadof(){
    return resultadof;
}
bool calpostfija::Valido() {
    return valido;
}
string calpostfija::Error() {
    return error;
}
void calpostfija::Ver_Result(){
    if (Valido()==0)
    //si es 0 significa que válido quedó en true
    {
        cout<<"El resultado de la expresión es: "<<Resultadof()<< endl;
    }
    else
    {
        cout<<"Su expresión es inválida por este error: "<<Error()<<endl;
    }
    
    
}
void calpostfija::Evaluarexp(){//todavía no sé si devuelve el resultado entonces lo dejo en void//
    string suma="+", resta="-";
    string multi="*", div="/";
    string pote="^", loga="_",  raiz="v";
    stack<double> pila;
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
            if (token.getValue().compare(suma)==0)
            //suma
            {
                resultadof=ope1+ope2;
                return;
            }
            else if (token.getValue().compare(resta)==0)
            //resta
            {
                resultadof=ope1-ope2;
                return;
            }
            else if (token.getValue().compare(multi)==0)
            //multiplicación
            {
                resultadof=ope1*ope2;//no importaría el orden pero igual...
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
            else if (token.getValue().compare(pote)==0)
            //potencia
            {
                resultadof= powf64(ope1,ope2);
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
                    resultadof=log10f64(ope1)/log10f64(ope2);// El cambio de base hace que el operador 2 sea la base
                    return;
                }
                
                
            }
            else if (token.getValue().compare(raiz)==0)
            //raiz, creo que es necesario especificar el operando 2 cuando es cuadrada...
            {
                if (ope2<0)//no puede ser raíz negativa
                {
                    error="Error: no trabajamos con números imaginarios...";
                    valido=false;
                    return;
                }
                else{
                    if (ope1>2)
                    //esto sería para la raíz enésima
                    {
                        resultadof=powf64(ope2,1/ope1);
                        return;
                    }
                    else if (ope1=2)
                    //lo hacemos con la funcion normal, en este caso sería porque ope1 debería ser 2 para raíz cuadrada
                    {
                        resultadof=sqrt(ope2);
                        return;
                    }
                    else if (ope1=1)
                    //raiz 1, es decir solo el número(no sé que tan necesario sea esta)
                    {
                        resultadof=ope2;
                        return;
                    }
                }
            }
            pila.push(resultadof);
        }  
    }
    if (pila.size() != 1)//no se completaron las operaciones
    {
        error = "Error: sobran operandos";
        valido = false;
        return;
    }
    resultadof=pila.top();//Al final solo se mostrará si es válido independiente de lo que haya
    Ver_Result();//Se enseña el resultado si fue válido
}