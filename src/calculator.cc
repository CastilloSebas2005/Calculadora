#include <queue>
#include <string>
#include <iostream>
#include <tokenizer.hh>
#include <token.hh>
#include <shunting_yard.hh>
#include <calculator.hh>
#include <postfija.hh>
#include <stdexcept>
#include <algorithm> // Para transform
#include <cctype>    // Para tolower

calculator::calculator(string input): inputUser(input){}

void calculator::printResult(int numberToPrint){
    cout<<"El resultado de su operación es: " << numberToPrint << endl;
}

bool calculator::evaluatorOfExpression(){
    transform(inputUser.begin(), inputUser.end(), inputUser.begin(), ::tolower);
    if(inputUser == "salir"){
        cout<<"Saliendo..."<<endl;
        return false;
    }
    else{
        try{
            tokenizer inputUserToTokens(inputUser);
            queue <Token> expressionToTokens = inputUserToTokens.getList();
            shunting_yard convertExpression(expressionToTokens);
            queue <Token> infixNotation = convertExpression.getOutputQueue();
            postfija solveExpression(infixNotation);
            double result = solveExpression.getResult();
            printResult(result);
        }catch(runtime_error& errorExpression){
            cerr << "Runtime error: " << errorExpression.what() << std::endl;
        }
        return true;
    }
}