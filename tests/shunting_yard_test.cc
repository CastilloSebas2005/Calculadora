#include <gtest/gtest.h>
#include <tokenizer.hh>
#include <queue>
#include <shunting_yard.hh>
#include <token.hh>

TEST(shunting_yardTest1, parentesisVacios){ 
    tokenizer test("()");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, corchetesVacios){ 
    tokenizer test("{}");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, cuadradosVacios){ 
    tokenizer test("[]");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, sum){ 
    tokenizer test("+");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    Token verificador = verificator.front();
    EXPECT_TRUE(!verificator.empty());
    EXPECT_EQ(verificador.getValue(), "+");
}

TEST(shunting_yardTest1, sumNums){ 
    tokenizer test("2+5");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 2);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 5);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador = verificator.front();
    EXPECT_EQ(operador.getValue(), "+");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}
