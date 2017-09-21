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

}
