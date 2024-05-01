#include <gtest/gtest.h>
#include <queue>
#include <shunting_yard.hh>
#include <token.hh>
#include <tokenizer.hh>
#include <postfija.hh>

TEST(postifixTest, sum){
    tokenizer sum("2 + 2");
    queue <Token> list = sum.getList();
    shunting_yard infixNotation(list);
    list = infixNotation.getOutputQueue();
    postfija test(list);
    
    double result = test.getResult();
    EXPECT_EQ(result, 4);
}