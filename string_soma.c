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
    numero = 0;
    /**
    * Agora, iremos fazer a soma de verdade. Dentro deste while, temos alguns if's que irão analizar
    * caracter por caracter da string. O while de dentro percorre o vetor de números para ver se o char é um numero.
    * A lógica utilizada aqui foi a seguinte: Le-se um char por vez e caso seja um número já faz a soma. 
    * Caso Lermos outro número, acrescentamos a ordem de significancia e subtraimos o que tinha anteriormente. Fazemos isso
    * com o contador chamado número.
    * Com as vírgulas, lêmos elas e acionamos a flag vírgula, além de incrementarmos o conta_virgulaque irá controlar
    * caso haja duas em seguida, ou mais de 3 em uma linha, ou outras anormalidades. Com caracteres especiais, nenhum é 
    * aceito, a menos que seja o \n ou a vírgula, ou caso formos mudar o delimitador.
    **/
    while(i<strlen(string_entrada)){ //percorre a string de entrada
        while(j<strlen(numeros)){ // percorre a string que contém os números

            if(string_entrada[i]==numeros[j] && numero == 0){ //caso seja o primeiro número lido

                algarismo[2] = 0; //O alarismo das centenas é zero
                algarismo[1] = 0; //O algarismo das dezenas é zero
                algarismo[0] = j; //O algarismo das unidades recebe o valor atual de j
                numero = 1; //O contador de números fica sendo 1
                virgula = 0; //A flag virgula continua 0

            }
            else if(string_entrada[i]==numeros[j] && numero == 1){ //caso seja o segundo numero em seguida
                soma = soma - algarismo[0]; // Subtraimos da soma o que tinha antes
                algarismo[2] = 0; //O algarismo das centenas ainda é zero
                algarismo[1] = algarismo[0]; //As dezenas será o que era unidades 
                algarismo[0] = j; //A unidade será o j
                numero = 2; //Contador de numeros será 2
                virgula = 0; // A flag vírgula ainda é 0
            }
            else if(string_entrada[i]==numeros[j] && numero == 2){//caso seja o terceiro numero em seguida
                soma = soma - 10*algarismo[1] - algarismo[0]; // Subtraimos da soma o que tinha antes
                algarismo[2] = algarismo[1]; // A centena recebe o que tinha na dezena
                algarismo[1] = algarismo[0]; //A dezena recebe o que tinha na unidade
                algarismo[0] = j; // A unidade recebe o valor de j
                numero = 3; //Contador de números agora é 3 (não pode passar disso pois o número maz aceito é 999)
                virgula = 0; // A flag vírgula é 0
            }
            else if(string_entrada[i]==numeros[j] && numero == 3){ //caso seja o quarto (ou mais) numero em seguida
                // Neste caso, houve um erro. Devemos retirar o número que tinha anteriormente e desconsiderar este número.
                soma = soma - 100*algarismo[2] - 10*algarismo[1] - algarismo[0]; //A soma é subtraida do número todo que tinha
                algarismo[2] = 0; //Centena é zerada
                algarismo[1] = 0; //Dezena é zerada
                algarismo[0] = 0; //Unidade é zerada
                numero = 3; //O contador de números continua 3 para que caso o proximo seja número, entre neste if de novo.
            }
            else if(string_entrada[i]==',' && i == (strlen(string_entrada)-3)) return -1; //caso a virgula for a ultima coisa digitada
            else if(string_entrada[i]==',' && !virgula && i != 0){ //caso o char for virgula e o anterior não e não for o primeiro char
                conta_virgula++; //O contador de virgula é incrementado
                virgula = 1; //Flag virgula é levantada
                numero = 0; //Flag número é zerada
                i++; //Passa para o proximo char
            }

            else if(string_entrada[i] == '\\' && string_entrada[i+1] == 'n' ) { //caso o char lido for \n
                virgula = 0;
                conta_virgula = 0; //O contador de vírgula é zerado, pois é uma nova linha
                numero = 0; // contador de número é zerado
                algarismo[2] = 0; //Centena zerada
                algarismo[1] = 0; //Dezena zerada
                algarismo[0] = 0; //Unidade zerada
                i += 2; //Pulamos 2 chars para continuar a leitura
                continue;
            }
            else if(string_entrada[i] == ',' && virgula) return -1; //caso sejam 2 virgulas consecutivas
            else if (conta_virgula > 2) return -1; // caso tenha mais de 3 numeros para somar

            j++; //Lêmos o próximo número no vetor numeros

        }
        total = algarismo[2]*100 + algarismo[1]*10 + algarismo[0]; //Acumulamos a soma em total
        soma = soma + total; // Somamos de fato
        j=0; //Zeramos o j para começarmos a ver o vetor de numeros do zero
        i++; //Passamos para o proximo char
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
