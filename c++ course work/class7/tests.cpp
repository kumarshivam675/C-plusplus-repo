#include <gtest/gtest.h>
#include "MyStack.h"

TEST(StackTest, testPop) {
    MyStack st;
    st.push(9);
    EXPECT_EQ(9, st.pop());
}

TEST(StackTest, testAll) {
    MyStack st;
    st.push(9);
    st.push(28);

    int val = st.pop();

    EXPECT_EQ(28, val); // Expect val to be 28
    EXPECT_NE(0, val); // Expect val not to be 0
    EXPECT_GT(29, val); // Greater than
    EXPECT_TRUE(val == 28) << "val somehow is not equal to 28"; // Print customized message

    // String Check
    EXPECT_STREQ("9 ", st.toString().c_str());
    EXPECT_STRCASEEQ("9 ", st.toString().c_str()); // Ignore case

    EXPECT_FLOAT_EQ(7.0, ((float) val) / 4);
    
    EXPECT_DOUBLE_EQ(7.0, ((double) val) / 4);
    EXPECT_NEAR(6.0, ((float) val) / 5, 1); // The difference is less than 1 

    //EXPECT_THROW(st.pop(), std::out_of_range);   // Expect st.pop() to throw an exception of OUT_OF...
    //EXPECT_ANY_THROW(st.pop());  // Expect st.pop() to throw an exception of any type
    //EXPECT_NO_THROW(st.pop());   // Expect st.pop() not to throw exception.



    ASSERT_EQ(28, val); // If this fails, the rest of current function is skipped  -- Fatal Error
    ASSERT_GT(29, val);
    ASSERT_TRUE(val == 28);
    ASSERT_STREQ("9 ", st.toString().c_str());
    ASSERT_STRCASEEQ("9 ", st.toString().c_str()); // Ignore case
}
