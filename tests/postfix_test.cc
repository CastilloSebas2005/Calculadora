#include <queue>
#include <shunting_yard.hh>
#include <token.hh>
#include <tokenizer.hh>
#include <postfija.hh>
#include <gtest/gtest.h>

TEST(postifixTest, sum){
    //test suma
    tokenizer sum("2 + 2");
    queue <Token> list = sum.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 4);
}
TEST(postifixTest, subs){
    //test resta
    tokenizer res("5 - 4");
    queue <Token> list = res.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 1);
}
TEST(postifixTest, mult){
    //test multiplicación
    tokenizer mult("5*4");
    queue <Token> list = mult.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 20);
}
TEST(postifixTest, div){
    //test división
    tokenizer div("25/5");
    queue <Token> list = div.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 5);
}
TEST(postifixTest, exp){
    //test potencia
    tokenizer pow("6^2");
    queue <Token> list = pow.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 36);
}
TEST(postifixTest, log){
    //test logaritmo
    tokenizer log("32_2");
    queue <Token> list = log.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 5);
}
TEST(postifixTest, rad){
    //test raiz
    tokenizer root("2v64");
    queue <Token> list = root.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 8);
}
