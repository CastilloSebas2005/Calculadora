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

TEST(shunting_yardTest1, rest){
    tokenizer test("-");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    Token verificador = verificator.front();
    EXPECT_TRUE(!verificator.empty());
    EXPECT_EQ(verificador.getValue(), "-");
}

TEST(shunting_yardTest1, mult){
    tokenizer test("*");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    Token verificador = verificator.front();
    EXPECT_TRUE(!verificator.empty());
    EXPECT_EQ(verificador.getValue(), "*");
}

TEST(shunting_yardTest1, div){
    tokenizer test("/");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    Token verificador = verificator.front();
    EXPECT_TRUE(!verificator.empty());
    EXPECT_EQ(verificador.getValue(), "/");
}

TEST(shunting_yardTest1, log){
    tokenizer test("_");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    Token verificador = verificator.front();
    EXPECT_TRUE(!verificator.empty());
    EXPECT_EQ(verificador.getValue(), "_");
}

TEST(shunting_yardTest1, raiz){
    tokenizer test("v");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    Token verificador = verificator.front();
    EXPECT_TRUE(!verificator.empty());
    EXPECT_EQ(verificador.getValue(), "v");
}

TEST(shunting_yardTest1, exp){
    tokenizer test("^");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    Token verificador = verificator.front();
    EXPECT_TRUE(!verificator.empty());
    EXPECT_EQ(verificador.getValue(), "^");
}

TEST(shunting_yardTest1, op1){
    tokenizer test("7*(26+5)");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 7);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 26);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 5);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "+");
    verificator.pop();
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "*");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, op2){
    tokenizer test("6_8^{7*(26+5)}");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 6);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(),8);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "_");
    verificator.pop();
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 7);
    verificator.pop();
    Token cuartoNumero = verificator.front();
    EXPECT_EQ(cuartoNumero.getNumber(), 26);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token quintoNumero = verificator.front();
    EXPECT_EQ(quintoNumero.getNumber(), 5);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "+");
    verificator.pop();
    Token operador3 = verificator.front();
    EXPECT_EQ(operador3.getValue(), "*");
    verificator.pop();
    Token operador4 = verificator.front();
    EXPECT_EQ(operador4.getValue(), "^");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, opAso1){
    tokenizer test("7+87.9-9");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 7);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 87.9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "+");
    verificator.pop();
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "-");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, opAso2){
    tokenizer test("7/87.9*9");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 7);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 87.9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "/");
    verificator.pop();
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "*");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, opAso3){
    tokenizer test("7v87.9^9");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 7);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 87.9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "v");
    verificator.pop();
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "^");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, opPrece1){
    tokenizer test("5+9*8");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 5);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 8);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "*");
    verificator.pop();
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "+");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, opPrece2){
    tokenizer test("5/9v8");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 5);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 8);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "v");
    verificator.pop();
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "/");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, opPrece3){
    tokenizer test("5-9^8");
    queue<Token> output = test.getList();
    shunting_yard testR(output);
    queue<Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(verificator.empty());
    Token primerNumero = verificator.front();
    EXPECT_EQ(primerNumero.getNumber(), 5);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token segundoNumero = verificator.front();
    EXPECT_EQ(segundoNumero.getNumber(), 9);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token tercerNumero = verificator.front();
    EXPECT_EQ(tercerNumero.getNumber(), 8);
    verificator.pop();
    EXPECT_FALSE(verificator.empty());
    Token operador1 = verificator.front();
    EXPECT_EQ(operador1.getValue(), "^");
    verificator.pop();
    Token operador2 = verificator.front();
    EXPECT_EQ(operador2.getValue(), "-");
    verificator.pop();
    EXPECT_TRUE(verificator.empty());
}

TEST(shunting_yardTest1, parenError){ 
    tokenizer test(")");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, parenError2){ 
    tokenizer test("(");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, parenCuaError){ 
    tokenizer test("]");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, parenCuaError2){ 
    tokenizer test("[");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, llavesError){ 
    tokenizer test("}");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, llavesError2){ 
    tokenizer test("{");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, parenOpError){ 
    tokenizer test("7+67-(8*5))");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, parenOpError2){ 
    tokenizer test(") 5 + 1 ( 8 + }{5+1)(");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

TEST(shunting_yardTest1, parenOpError3){ 
    tokenizer test("5^74-8[(9^8/15)25^9_112]}");
    queue <Token> output = test.getList();
    EXPECT_THROW({
        shunting_yard testR(output);
    }, std::runtime_error);
}

