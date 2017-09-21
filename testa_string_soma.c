//#include <limits.h>
//#include "gtest/gtest.h"
#include "string_soma.h"

// Testes de soma_string

// Testes em casos que dão certo a soma com a vírgula delimitando
TEST(soma_stringTest, SomasOks) {
  

  EXPECT_EQ(3, soma_string("1,2\\n"));
  EXPECT_EQ(6, soma_string("1,2,3\\n"));
  EXPECT_EQ(3, soma_string("1\\n,2"));
  EXPECT_EQ(5, soma_string("1\\n\\n\\n,4\\n"));
  EXPECT_EQ(10, soma_string("1,2,3\\n,4\\n"));
  EXPECT_EQ(2, soma_string("2000,2\\n"));
  EXPECT_EQ(1000, soma_string("500,500\\n"));
  EXPECT_EQ(2, soma_string("2,3000\\n"));
  EXPECT_EQ(1998, soma_string("999,999\\n"));
  EXPECT_EQ(300, soma_string("100,100,100\\n"));
}

// Testes que o retorno deve ser -1
TEST(soma_stringTest, SomasOks) {
  

  EXPECT_EQ(-1, soma_string("1,\\n"));
  EXPECT_EQ(, soma_string(",2\\n"));
  EXPECT_EQ(3, soma_string("1,,2\\n"));
  EXPECT_EQ(5, soma_string(",\\n"));
  EXPECT_EQ(10, soma_string("1;2\\n"));
  EXPECT_EQ(2, soma_string("1,2 \\n"));
  EXPECT_EQ(1000, soma_string("1,2"));
  EXPECT_EQ(2, soma_string("1,2 "));
  EXPECT_EQ(1998, soma_string("1,2,3,4\\n"));
  EXPECT_EQ(300, soma_string("-1,-2\\n"));
}

//RUN_ALL_TESTS()
