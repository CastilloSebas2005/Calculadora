#include <gtest/gtest.h>
#include <tokenizer.hh>


TEST(tokenizerTest, tokenizerInput){ 

    tokenizer test ("354564564564+54545456"); //probando funcionalidad de una parte del constructor de tokenizer
    EXPECT_EQ(test.getSizeArray(), 3);
    
    tokenizer test1 ("3+5*9_3"); //probando funcionalidad de una parte del constructor de tokenizer
    EXPECT_EQ(test1.getSizeArray(), 7);

    tokenizer test2 ("35_3v45v7v778"); //probando funcionalidad de una parte del constructor de tokenizer
    EXPECT_EQ(test2.getSizeArray(), 9);

    
}
