#include <queue>
#include <string>
#include <iostream>
#include <tokenizer.hh>
#include <token.hh>
#include <shunting_yard.hh>
#include <calculator.hh>
#include <postfija.hh>

calculator::calculator(){
    string expression;
    getline(cin, expression);
    evaluatorOfExpression(expression);
}

void calculator::printResult(int numberToPrint){
    cout<<"El resultado de su operación es: " << numberToPrint << endl;
}

void calculator::evaluatorOfExpression(string input){
    tokenizer inputUserToTokens(input);
    queue <Token> expressionToTokens = inputUserToTokens.getList();
    shunting_yard convertExpression(expressionToTokens);
    queue <Token> infixNotation = convertExpression.getOutputQueue();
    postfija solveExpression(infixNotation);
    double result = solveExpression.getResult();
    printResult(result);
}