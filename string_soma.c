#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_soma.h"

/**
* Funcão soma_string, recebe uma string e retorna a soma dos números. Só aceita como delimitador a vírgula.
* Consegue somar 3 números por linha, sendo que cada número pode ser de 0 a 999.
* Não soma números negativos, somente números naturais.
* Caso algum caracter da string não seja válido, a função retornará -1
**/
int soma_string(char *string_entrada){
    char numeros[11] = {'0','1','2','3','4','5','6','7','8','9','\0'}; //Vetor que contém todos os números
    char ch_especiais[29] = {' ','!','@','#','$','%','&','*','(',')','-','_','+','=','`','{','}','[',']','^','~',';',':','?','>','<','.','\0'};// vetor que contém ch, especiais
	int i = 0, j = 0, k = 0, l = 0; // Contadores para usarmos em for's e while
    int soma = 0; //Variável que acumula a soma
    int total = 0; // Variável auxiliar na soma
    int virgula = 0; //Flag que é ativa caso ler uma vírgula
    int numero = 0; //Contador que é incrementado caso um número seja lido
    int conta_virgula = 0; //Contador que conta a quantidade de vírgulas em uma linha, não pode passar de 2
    int algarismo[3] = {0,0,0}; // Vetor que guarda a significância dos algarismos de um numero


    for(k=0;k<strlen(numeros);k++) { //Caso o primeiro caracter for número
        if(string_entrada[0] == numeros[k]){
            numero = 1;
        k++;
        }
    }
    if(string_entrada[strlen(string_entrada)-2] != '\\' && string_entrada[strlen(string_entrada)-1] != 'n'){ //Se no final da string não tiver \n
        return -1;
    }

        if (!numero && (string_entrada[0] != '/' || string_entrada[1] != '/')){ //caso o inicio da string não for um número nem //
            return -1;

        }
    for(k=0;k<strlen(string_entrada);k++){ // Este for detecta se tem um caracter especial, se tiver, retorna -1
        for(l=0;l<strlen(ch_especiais);l++){
            if(string_entrada[k]==ch_especiais[l]){
                return -1;
            }
        }
    }
    
	}
	return soma; // Retornamos por fim a soma

}

/**
* mudaDelimitador é a função que recebe uma string e retorna outra string.
* A string retornada é a mesma caso a string inicial não começe com "//[" sem aspas. 
* Caso a string inicial comece com "//[", a string de saida será a original, porém com o delimitador modificado 
* para vírgulas, para que a função de cima consigue utilizá-la.
* exemplo:  string_entrada: //[##]\n3##2##1
*           string_entrada_nova: 3,2,1
**/

char* mudaDelimitador(char *string_entrada){
    int j; //Contador para for
    int tam = 0; //Variavel que armazena o tamanho do delimitador
    char *p; // Ponteiro para char que será o delimitador
    int virgula = 0; // Flag levantada quando o char lido for uma virgula
    char *string_entrada_nova; // Ponteiro para char que será a nova string


    /**
    * Este if será o if principal. Caso a string entrada começar com //[ significa que o usuario está pedindo para redefinir
    * o delimitador padrão para o que ele digitar. Para isso faremos o seguinte:
    * Encontraremos qual o delimitador padrão que o usuario quer. Armazenaremos no ponteiro p.
    * Em seguida, iremos retirar os caracteres iniciais da string de entrada que são: //[Delimit]. A string final ficará
    * somente com os números e o novo delimitador.
    * Após isso, iremos substituir o delimitador novo por virgulas: procuramos na string o delimitador, retiramos o primeiro
    * caracter e modificamos a string nova, que será a saida. Apos isso, os outros chars serão ignorados na nova string.
    **/
    if (string_entrada[0] == '/' && string_entrada[1] == '/'){ // Caso a string começe com //

        tam = 0; //Define o tamanho do delimitador inicialmente para 0
        while (string_entrada[tam+3] != ']'){ // Conta o tamanho do delimitador
            tam++;
        }
        if (string_entrada[4+tam] != '\\' && string_entrada[5+tam] != 'n'){ //Caso depois do delimitador não tenha um \n, retorna a propria entrada
            return string_entrada;
        }
    p = (char *) malloc(tam*sizeof(char)); //Aloca espaço para a string que armazenará o delimitador
    string_entrada_nova = (char *) malloc(strlen(string_entrada)*sizeof(char)); //Aloca espaço para a string nova, que será a saída

    for(j=0;j<tam;j++){ // Armazena o delimitador em p
        p[j] = string_entrada[j+3];
    }

    for(j=0;j<(strlen(string_entrada));j++){ //Retira os caracteres iniciais //[delim]\n
        string_entrada[j] = string_entrada[j+tam+6];
    }
    printf("%s",string_entrada);
        j = 0;
        for(int k=0;k<strlen(string_entrada);k++){ //Este for percorrerá a string
        if (string_entrada[k] == p[j] && !virgula){ //Comparação para ver se o char é igual ao delimitador
                string_entrada_nova[k] = ','; //Troca o delimitador por virgula
                virgula = 1; //Seta a flag virgula, para que não troque todos os chars por virgulas
                if (j < tam-1) j++; //Incrementa j caso não estoure o tamanho tam
                else if (j == tam-1) {
                    virgula = 0;
                    j = 0;
                }
        }
        else if(string_entrada[k] == p[j] && virgula){ //Comparação para ver se o char é igual ao delimitador mas o antigo também
            if (j < tam-1) j++; //Somente incremente j
            else if (j == tam-1) {
                j = 0;
                virgula = 0;
            }
        }
            
        else if(string_entrada[k] != p[j]){ //Se não for igual ao delimitador, quer dizer que é numero, então armazena na nova
            string_entrada_nova[k] = string_entrada[k];
            virgula = 0;
            j = 0;
        }
    }
    return string_entrada_nova; //Retorna a nova string, com virgulas
    }
    else{ //Se a string não comaça com //, somente retorna a propria string
        return string_entrada;
    }
}
