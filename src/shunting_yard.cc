#include <iostream>
#include <queue> 
#include <string>
#include <token.hh>
#include <tokenizer.hh>
#include <shunting_yard.hh>

using namespace std;


shunting_yard::shunting_yard(tokenizer tokenList): tokenList(tokenList){
    tokenQueue = tokenList.getList();
    while(!tokenQueue.empty()){
        Token token = tokenQueue.front();
        if(token.isNumber()){
            output_Queue.push(token);
            cout<<"Leyendo:"<<token.getNumber()<<endl;
            tokenQueue.pop();
        }
        else if(token.isOperator()){
        /*Mientras que el operador a ingresar sea de mayor precedencia, 
            pushee los operadores que estaban en el stack a la cola de salida
        */

       // al final pushee ese operador actual al stack

       /*Si es un bracket izquierdo, anadalo al stack
       */

      //Si es un bracket derecho

      /*
      Mientras que no haya un bracket izquierdo en el stack
        Ponga elementos del stack a la cola de salida
      */

     //Quite el bracket izquierdo del stack
     
     //Mientras hayan operadores en el stack, anadalos a la pila
        }
    }
}

//Terminar y ver como se hara la precedencia
int shunting_yard::getPrecedence(Token tokenOperator){
    string tokenOp = tokenOperator.getValue();
    if(tokenOp == "+"){
        return 1;
    }
}

queue <Token>shunting_yard::getOutputQueue(){
    return output_Queue;
}
