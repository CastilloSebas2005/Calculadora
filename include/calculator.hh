#ifndef CALCULATOR_HH
#define CALCULATOR_HH

#include <string>

using namespace std;

class calculator{
    public:
        calculator(string input);
        bool evaluatorOfExpression();
    private:
        string inputUser;
        bool controlWhile;
        void printResult(int numberToPrint);
};

#endif