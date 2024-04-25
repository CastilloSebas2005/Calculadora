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
            //tokenQueue.pop();
        }
        else if(token.isOperator()){

        }
    }
}
