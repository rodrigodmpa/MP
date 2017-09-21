#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_soma.h"
//#include "gtest/gtest.h"


/**
* Programa principal
* Aplica a calculadora de string em uma entrada
* Realiza a soma, mudando o delimitador caso precise
* Printa na tela a Entrada fornecida e a saída calculada.
**/
int main(int argc, char const *argv[])
{
char entrada[1000],nova_entrada[1000];
char *p;
int saida,comp;

scanf("%[^\n]",entrada); //Leitura da string de entrada

p = mudaDelimitador(entrada); //Chamamos a fução que muda o delimitador, caso seja necessário.
int k=0;
for(int i=0;i<strlen(entrada);i++){ // Neste for, passamos a resposta final para a nova_entrada, a qual usamos para somar.
    if(*(p+i) !=  '\0'){
    nova_entrada[k] = *(p+i);
    k++;
}
}
saida = soma_string(nova_entrada); //Chamamos a função soma_string, passando como argumento a nova_entrada
printf("\nEntrada:%s\n",entrada); //Mostramos na tela o resultado
printf("Saida:%d\n",saida);



return 0;

}