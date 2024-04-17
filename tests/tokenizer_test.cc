#include <gtest/gtest.h>
#include <tokenizer.hh>


TEST(tokenizerTest, tokenizerInput){ 

    tokenizer test ("3 + 5 + 8 + 9 + 7 + 5"); //probando funcionalidad de una parte del constructor de tokenizer
    EXPECT_EQ(test.getSizeArray(), 11);
    tokenizer test2 ("&3  + 5 *+ 8 + 9 + 7 / +  5");
    EXPECT_EQ(test2.getSizeArray(), 14);
    
}
