#include <iostream>
#include <queue> 
#include <string>
#include <token.hh>
#include <tokenizer.hh>
#include <shunting_yard.hh>

using namespace std;


shunting_yard::shunting_yard(tokenizer tokenList): tokenList(tokenList){
    //Declaracion de tokenQueue como la cola de tokenizer
    tokenQueue = tokenList.getList();
    //El shunting yard se hara mientras haya tokens que leer del tokenQueue
    while(!tokenQueue.empty()){
        Token token = tokenQueue.front();
        //Si el token es un numero, se va a la cola de salida
        if(token.isNumber()){
            output_Queue.push(token);
            cout<<"Leyendo:"<<token.getNumber()<<endl;
            tokenQueue.pop();
        }
        //si el token es un operador, se hace el siguiente caso
        if(token.isOperator()){
            /*Mientras el stack de operadores no este vacio, el principio del stack no sea un parentesis izq y 
            el token del stack de operadores tenga mayor precedencia que la del token de la lista de tokens o 
            sean de misma precedencia, entonces los operadores que estaban en el stack de operadores, se van
            a pasar a la cola de salida, por ultimo el token con menor precedencia se pasara al stack de 
            operaciones*/
            
            //Aun no acomoda tan bien las cosas
            while(!operation_Stack.empty() && 
                !operation_Stack.top().isParenthesesLeft() && 
                (getPrecedence(operation_Stack.top()) > getPrecedence(token) || 
                getPrecedence(operation_Stack.top()) == getPrecedence(token))){
                output_Queue.push(operation_Stack.top());
                operation_Stack.pop();
            }
            operation_Stack.push(token);
            tokenQueue.pop();

        }
        //si el token es un parentesis izquierdo, se pasara al stack de operaciones
        if(token.isParenthesesLeft()){
            operation_Stack.push(token);
            tokenQueue.pop();
        }
        //si el token es un parentesis derecho, se hara el siguiente caso
        if(token.isParenthesesRight()){
            /*Mientras el stack de operaciones no este vacio y el primer operador del mismo no sea un parentesis
            izquierdo,anada a la cola de salida, el primer operador del stack de operaciones
            */
            while(!operation_Stack.empty() && 
                !operation_Stack.top().isParenthesesLeft()){
                output_Queue.push(operation_Stack.top());
                operation_Stack.pop();
            }
            //si el operador es un parentesis izquierdo, se elimina del stack de operaciones
            if(!operation_Stack.empty() && 
                operation_Stack.top().isParenthesesLeft()){
                operation_Stack.pop();
            }
        }
    }
    /*Aparte, si quedan operadores en el stack de operaciones y el primer operador no es un parentesis
    izquierdo, el operador que este de primero en el stack, se anadira en el token de salida*/
    while(!operation_Stack.empty() && 
        !operation_Stack.top().isParenthesesLeft()){
        output_Queue.push(operation_Stack.top());
        operation_Stack.pop();
    }
    
}

void shunting_yard::obtenerQueue(){
    while(!output_Queue.empty()){
        Token token = output_Queue.front();
        cout<<token.getValue()<<", ";
        output_Queue.pop();
    }
    cout<<endl;
}

int shunting_yard::getPrecedence(Token tokenOperator){
    string tokenOp = tokenOperator.getValue();
    if(tokenOp == "^" || tokenOp == "_" || tokenOp == "V"){
        return 3;
    }
    else if(tokenOp == "*" || tokenOp == "/"){
        return 2;
    }
    else if(tokenOp == "+" || tokenOp == "-"){
        return 1;
    }
    return 0;
}

queue <Token>shunting_yard::getOutputQueue(){
    return output_Queue;
}

