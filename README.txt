Aluno: Rodrigo Demetrio Palma - 150147384

Como funciona o programa:

-Para rodar o programa, entre na pasta pelo terminal e digite make, em seguida, digite: .\exec

-O programa irá esperar a string de entrada. Para finalizar a leitura aperte ENTER.

-Para simular outros ENTERS (\n) dentro da própria string, escreva "\n" sem aspas. Exemplo:


Entrada				Saida
1,2\n,3\n[ENTER]      --> 	6		No fim da entrada sempre deve ter \n
//[#]\n1#2#3\n[ENTER] --> 	6		Definiu-se um delimitador.Após definir, deve ter \n
1,2,3[ENTER]	      -->	-1		Não tem o \n no fim da string.

IMPORTANTE:É necessário ESCREVER o \n na entrada ao invés de apertar ENTER. O pressionar de enter irá finalizar a leitura da string de entrada.

-Só é possivel definir 1 único delimitador por vez.

-Os testes podem ser vistos no modulo testa_string_soma.c.

-O módulo testa_soma_string_stdin.c é o módulo (main), onde o usuário digita as entradas.

-O documento entradas.txt pode ser utilizado para testar algumas entradas no terminal, basta reescreve-las depois de digitar make, uma por vez.

-O documento cppcheckAnalize foi feita a analize dos erros encontrados quando utilizada a flag cppcheck --enable=warning.

