#include <gtest/gtest.h>
#include <tokenizer.hh>
#include <queue>

TEST(tokenizerTest, sum){ 
    tokenizer test ("+");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isOperator());
    EXPECT_EQ(verificator.getValue(), "+");
}
TEST(tokenizerTest, rest){ 
    tokenizer test ("-");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isOperator());
    EXPECT_EQ(verificator.getValue(), "-");
}

TEST(tokenizerTest, div){ 
    tokenizer test ("/");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isOperator());
    EXPECT_EQ(verificator.getValue(), "/");
}
TEST(tokenizerTest, mult){ 
    tokenizer test ("*");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isOperator());
    EXPECT_EQ(verificator.getValue(), "*");
}
TEST(tokenizerTest, rad){ 
    tokenizer test ("v");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isOperator());
    EXPECT_EQ(verificator.getValue(), "v");
}
TEST(tokenizerTest, log){ 
    tokenizer test ("_");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isOperator());
    EXPECT_EQ(verificator.getValue(), "_");
}
TEST(tokenizerTest, exp){ 
    tokenizer test ("^");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isOperator());
    EXPECT_EQ(verificator.getValue(), "^");
}
TEST(tokenizerTest, num_1digit){ 
    tokenizer test ("5");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isNumber());
    double number = 5;
    EXPECT_EQ(verificator.getValue(), to_string(number));
    EXPECT_EQ(verificator.getNumber(), number);
}
TEST(tokenizerTest, numBiggerDigit){ 
    tokenizer test ("54456897889");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isNumber());
    double number = 54456897889;
    EXPECT_EQ(verificator.getValue(), to_string(number));
    EXPECT_EQ(verificator.getNumber(), number);
}
TEST(tokenizerTest, numDecDigit){ 
    tokenizer test ("0.4");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isNumber());
    double number = 0.4;
    EXPECT_EQ(verificator.getValue(), to_string(number));
    EXPECT_EQ(verificator.getNumber(), number);
}
TEST(tokenizerTest, numDecBiggerDigit){ 
    tokenizer test ("0.478748");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isNumber());
    double number = 0.478748;
    EXPECT_EQ(verificator.getValue(), to_string(number));
    EXPECT_EQ(verificator.getNumber(), number);
}
TEST(tokenizerTest, numBiggerDecBiggerDigit){ 
    tokenizer test ("78985.478748");
    queue <Token> element = test.getList();
    EXPECT_TRUE(!element.empty());
    Token verificator = element.front();
    EXPECT_TRUE(verificator.isNumber());
    double number = 78985.478748;
    EXPECT_EQ(verificator.getValue(), to_string(number));
    EXPECT_EQ(verificator.getNumber(), number);
}