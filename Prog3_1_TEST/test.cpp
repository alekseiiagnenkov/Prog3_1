#include "pch.h"
#include "../Prog3_1/Set.cpp" 

TEST(StringConstructor, Constructor) {
    prog3_1::Set s1;
    prog3_1::Set s2(10);
    ASSERT_EQ(0, s1.getSize());
    ASSERT_EQ(10, s2.getSize());
}

TEST(StringConstructor, TestException) {
    ASSERT_ANY_THROW(prog3_1::Set s1(-3));
    ASSERT_ANY_THROW(prog3_1::Set s2("ll"));
}

TEST(StringMethods, Setter) {
    prog3_1::Set s1, s2;
    s1.setSize(3);
    ASSERT_EQ(3, s1.getSize());
    ASSERT_ANY_THROW(s1.setSize(-1));
    ASSERT_ANY_THROW(s2.setARR("ll"));
}
TEST(StringMethods, Parametrs) {
    prog3_1::Set s1("helLo");
    ASSERT_ANY_THROW(s1.add_el('l'));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}