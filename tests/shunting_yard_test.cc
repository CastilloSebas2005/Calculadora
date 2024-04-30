#include <gtest/gtest.h>
#include <tokenizer.hh>
#include <queue>
#include <shunting_yard.hh>
#include <token.hh>

TEST(shunting_yardTest1, sum){ 
    tokenizer test("()");
    queue <Token> output = test.getList();
    shunting_yard testR (output);
    queue <Token> verificator = testR.getOutputQueue();
    EXPECT_FALSE(!verificator.empty());
}
