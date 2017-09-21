#include <limits.h> //Caso necessite, descomente
#include "gtest/gtest.h"
#include "string_soma.h"

// Testes de soma_string

// Testes em casos que dão certo a soma com a vírgula delimitando
TEST(soma_stringTest, SomasOks) {
  

  EXPECT_EQ(3, soma_string("1,2\\n")); //Soma padrão com 2 numeros
  EXPECT_EQ(6, soma_string("1,2,3\\n")); //Soma padrao com 3 numeros
  EXPECT_EQ(3, soma_string("1\\n,2")); //Soma com 2 numeros e um \n no meio
  EXPECT_EQ(5, soma_string("1\\n\\n\\n,4\\n"));  // \n no meio de numeros é ignorado
  EXPECT_EQ(10, soma_string("1,2,3\\n,4\\n")); //Soma normal com 3 numeros \n no meio e mais um numero depois
  EXPECT_EQ(2, soma_string("2000,2\\n")); // Se for colocado o 2000 no inicio, ele é ignorado
  EXPECT_EQ(1000, soma_string("500,500\\n")); //Soma com numeros de 3 algarismos
  EXPECT_EQ(2, soma_string("2,3000\\n")); //Se for colocado o 3000 no fim, ele é ignorado
  EXPECT_EQ(1998, soma_string("999,999\\n")); //Testando os  limites
  EXPECT_EQ(300, soma_string("100,100,100\\n")); //Soma com 3 numeros de 3 algarismos
}

// Testes que o retorno deve ser -1
TEST(soma_stringTest, SomasNotOks) {
  

  EXPECT_EQ(-1, soma_string("1,\\n")); //Virgula no fim, erro
  EXPECT_EQ(-1, soma_string(",2\\n")); //Virgula no inicio, erro
  EXPECT_EQ(-1, soma_string("1,,2\\n")); //Duas virgulas, erro
  EXPECT_EQ(-1, soma_string(",\\n")); //Somente uma virgula, erro
  EXPECT_EQ(-1, soma_string("1;2\\n")); //Caracter especial não especificado, erro
  EXPECT_EQ(-1, soma_string("1,2 \\n")); //Espaço, erro
  EXPECT_EQ(-1, soma_string("1,2")); //Sem \n no fim, erro
  EXPECT_EQ(-1, soma_string("1,2 ")); //Espaço no fim e sem \n, erro
  EXPECT_EQ(-1, soma_string("1,2,3,4\\n")); //4 numeros na mesma linha, erro
  EXPECT_EQ(-1, soma_string("-1,-2\\n")); //Numeros negativos, erro
}
// Testes que relacionam o delimitador
TEST(DelimitadorTests, DelimitadoresOks) {
  

  EXPECT_EQ(6, soma_string(muda_delimitador("//[#]\\n1#2#3\\n"))); //Delimitador de tamanho 1
  EXPECT_EQ(3, soma_string(muda_delimitador("//[#$&]\\n1#$&2#$&3\\n"))); //Delimitador de tamanho 3 variado
  EXPECT_EQ(5, soma_string(muda_delimitador("//[#$&]\\n2000#$&2#$&3\\n"))); //Ignorar o 2000
  EXPECT_EQ(10, soma_string(muda_delimitador("//[!]\\n1!2!3\n!4\\n"))); //Ignorar o \n entre numeros
  EXPECT_EQ(2, soma_string(muda_delimitador("//[#]\\n2#2222\\n"))); //Ignorar o 2222 no fim
  EXPECT_EQ(2297, soma_string(muda_delimitador("//[###]\\n999###999###999\\n"))); //Testando os limites
  EXPECT_EQ(5, soma_string(muda_delimitador("//[#$&]\\n2000#$&2#$&3\\n"))); //Ignorar o 2000 com delimitador um pouco maior
  EXPECT_EQ(5, soma_string(muda_delimitador("//[#$&]\\n1000#$&2#$&3\\n"))); //

}
// Testes que relacionam os delimitadores que devem retornar -1
TEST(DelimitadorTests, DelimitadoresNotOks) {
  

  EXPECT_EQ(-1, soma_string(muda_delimitador("//[#]\\#3\\n"))); // Iniciar com o delimitador
  EXPECT_EQ(-1, soma_string(muda_delimitador("//[#$&]\\3#$&\\n"))); //Terminar com o delimitador
  EXPECT_EQ(-1, soma_string(muda_delimitador("//[#$&]\\n1#$&2#$&3#$&4\\n"))); //mais de 3 numeros na mesma linha
  EXPECT_EQ(-1, soma_string(muda_delimitador("//[!]\\n1!!2!!3\\n"))); //Dois delimitadores consecutivos
  EXPECT_EQ(-1, soma_string(muda_delimitador("//[#]\\n2#2#3"))); //Sem \n no final
  EXPECT_EQ(-1, soma_string(muda_delimitador("//[#]9#9#9\\n"))); //Sem \n depois de definir o delimitador
  EXPECT_EQ(-1, soma_string(muda_delimitador("//[#$&]\\n2000#$&2#$&3\\n"))); //Ignorar o 2000 com delimitador um pouco maior
  EXPECT_EQ(-1, soma_string(muda_delimitador("//#$&\\n1000#$&2#$&3\\n"))); // Definiu delimitador sem abrir e fechar colchetes
  EXPECT_EQ(-1, soma_string(muda_delimitador("[#$&]\\n1000#$&2#$&3\\n"))); // Definiu delimitador sem iniciar com //
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
