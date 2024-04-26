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

    while(!tokenQueue.empty()){
        Token token = tokenQueue.front();
        if(token.isNumber()){
            output_Queue.push(token);
            cout<<"Leyendo:"<<token.getNumber()<<endl;
            tokenQueue.pop();
        }
        else if(token.isOperator()){
            operation_Stack.push(token);
            tokenQueue.pop();
        }
        else if(token.isParenthesesLeft()){
            operation_Stack.push(token);
            tokenQueue.pop();
        }
        else if(token.isParenthesesRight()){
            while(!operation_Stack.top().isParenthesesLeft()){
                output_Queue.push(operation_Stack.top());
                cout<<"Leyendo:"<<token.getValue()<<endl;
                operation_Stack.pop();
            }
            operation_Stack.pop();
        }
    }
    while(!operation_Stack.empty()){
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
    if(tokenOp == "^" ){
        return 1;
    }
    else if(tokenOp == "_"){
        return 2;
    }
    else if(tokenOp == "*"){
        return 3;
    }
    else if(tokenOp == "/"){
        return 4;
    }
    else if(tokenOp == "+"){
        return 5;
    }
    else if(tokenOp == "-"){
        return 6;
    }
    return 0;
}

queue <Token>shunting_yard::getOutputQueue(){
    return output_Queue;
}

