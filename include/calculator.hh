#ifndef CALCULATOR_HH
#define CALCULATOR_HH

#include <string>

using namespace std;

class calculator{
    public:
        calculator();
    private:
        string inputUser;
        void printResult(int numberToPrint);
        void evaluatorOfExpression(string input);
};

#endif