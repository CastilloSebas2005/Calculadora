#include <iostream>
#include <queue> 
#include <string>
#include <token.hh>
#include <tokenizer.hh>
#include <shunting_yard.hh>

using namespace std;


shunting_yard::shunting_yard(tokenizer tokenlist): tokenList(tokenlist){
        tokenQueue = tokenList.getList();
        while(!tokenQueue.empty()){
            Token token = tokenQueue.front();
            if(token.isNumber()){
                output_Queue.push(token);
            }
            else if(token.isOperator()){
                processOperators(token);
                operation_Stack.push(token);
                
            }
            else if(token.isParenthesesLeft()){
                operation_Stack.push(token);
            }else if(token.isParenthesesRight()){
                while(!operation_Stack.empty() && !operation_Stack.top().isParenthesesLeft()){
                    output_Queue.push(operation_Stack.top());
                    operation_Stack.pop();
                }
                if(!operation_Stack.empty() && operation_Stack.top().isParenthesesLeft()){
                         operation_Stack.pop();  
                }
            }
            tokenQueue.pop();
        }
        while(!operation_Stack.empty()){
            Token token = operation_Stack.top();
            output_Queue.push(token);
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
    if(tokenOp == "^" || tokenOp == "_" || tokenOp == "v"){
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

void shunting_yard::processOperators(Token firstOperation){
    while(!operation_Stack.empty() && (!operation_Stack.top().isParenthesesLeft())
    && (getPrecedence(operation_Stack.top()) >= getPrecedence(firstOperation))
    && asociativeLeft(firstOperation)){
        output_Queue.push(operation_Stack.top());
        operation_Stack.pop();
    }
}

bool shunting_yard::asociativeLeft(Token tokenOperator){
    if(tokenOperator.getValue() == "+"
    || tokenOperator.getValue() == "-"
    || tokenOperator.getValue() == "*"
    || tokenOperator.getValue() == "/"){
        return true;
    }else{
        return false;
    }
}