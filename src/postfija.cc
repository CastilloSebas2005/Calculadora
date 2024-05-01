#include <stack>
#include <queue>
#include <token.hh>
#include <string>
#include <postfija.hh>
#include <cmath>
#include <iostream>

postfija::postfija(queue <Token> tokenqueue):tokenQueue(tokenqueue){
    stack <Token> tokenStack;
    double Result = 0;
    while(!tokenqueue.empty()){
        Token token = tokenqueue.front();
        tokenqueue.pop();
        if(token.isNumber()){
            tokenStack.push(token);
        }
        else if(token.isOperator()){
            Token operand2 = tokenStack.top();
            tokenStack.pop();
            Token operand1 = tokenStack.top();
            tokenStack.pop();
            string operation = token.getValue();
            //se usa operation[0] para poder hacer el switch y comparar como caractéres
            switch (operation[0])
            {
            case '+':
                Result = operand1.getNumber() + operand2.getNumber();
                break;
            case '-':
                Result = operand1.getNumber() - operand2.getNumber();
                break;
            case '*':
                Result = operand1.getNumber() * operand2.getNumber();
                break;
            case '/':
                Result = operand1.getNumber() / operand2.getNumber();
                break;
            case '_':
                Result = log(operand1.getNumber())/log(operand2.getNumber());
                break;
            case '^':
                Result = pow(operand1.getNumber(), operand2.getNumber());
                break;
            case 'v':
                Result = pow(operand2.getNumber(), (1/operand1.getNumber()));
            default:
                break;
            }
            Token saveResult(TokenType::TOKEN_TYPE_NUMBER, to_string(Result));
            tokenStack.push(saveResult);
        }
        if(tokenStack.size() == 1){
            Token Result = tokenStack.top();
            result = Result.getNumber();
        }
    }

}

double postfija::getResult(){return result;}