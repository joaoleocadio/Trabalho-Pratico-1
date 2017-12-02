#include <stdio.h>
#include "utils.h"
#include <string.h>
#define TAMANHO 10
#define TAMTOKENS 1
#define N_PLAYERS 25

void clean_buffer(){char ch; while ((ch = getchar()) != '\n' && ch != EOF);}

void preencherMatriz(char mat[TAMANHO][TAMANHO])
{
    int i, j;
    int num = '0';
    char abc = 'A';
    
    mat[1][1] = " "; //posição [1][1] da matriz preenchida com espaço em branco
    
    for (i = 1; i < TAMANHO; ++i)    //preenche a 1ª linha com letras (A a I)
    {
        mat[0][i] = abc;
        ++abc; 
    }

    for (i = 1; i < TAMANHO; ++i)   //preencher a 1ª coluna com números (1 a 9)
    {
        mat[i][0] = num + i;
    } 
    
    for (i = 1; i < TAMANHO; ++i)   //preencher o resto da matriz com '-'
    {
        for (j = 1; j < TAMANHO; ++j)
        {
            mat[i][j] = '-';            
        }    
    }    
}

void imprimirMatriz(char mat[TAMANHO][TAMANHO])
{
    int i, j;
    i = j = 0;
    
    printf("\tApresentação do tabuleiro de jogo\n ");
    
    for (i = 0; i < TAMANHO; ++i)
    {
        for (j = 0; j < TAMANHO; ++j)
        {
            printf("%c", mat[i][j]);
            printf("|");
        }
        puts(" ");// para a matriz ficar quadrada
    }   
}
int lerString(char *string, int max) 
{     
    if (fgets(string, max, stdin) != NULL) 
    {
    int tamanho = strlen(string) - 1;
        if (string[tamanho] == '\n') { string[tamanho] = '\0'; } 
        else{ clean_buffer(); }
        return 1;
    }
    return 0;
}

void apresentacao()
{
    printf("\tJogo 3 em linha!");
    printf("\n");
    printf("\n");
}

void escolherTokens(char tokens[])
{
    int i;
    char jogador1[N_PLAYERS];
    char jogador2[N_PLAYERS];
    
    for (i = 0; i < 1; ++i)
    {                                      //Inserir o nome do jogador 1
        printf("Jogador nº %d\n", i + 1);
        printf("Introduza o seu nome: ");
        lerString(jogador1, N_PLAYERS);
    }
    
    for (i = 0; i < 1; ++i)
    {                                      //Inserir o nome do jogador 2
        printf("Jogador nº %d\n", i + 2);
        printf("Introduza o seu nome: ");
        lerString(jogador2, N_PLAYERS);
    } 
    
    for(i = 0; i < TAMTOKENS; ++i)
    {                                      //Escolhe token para cada jogador
        printf("%s escolha o seu token: ",jogador1);
        scanf("%c", &tokens[0]);            //guardar no indice 0 do vetor
        clean_buffer();
        printf("%s escolha o seu token: ",jogador2);
        scanf("%c", &tokens[1]);            //guardar no indice 1 do vetor
        if(tokens[0] == tokens[1])          //comparar as posições e decrementar ate que escolham 
        {                                   //tokens diferente
            i-=1;
            puts("Os tokens são iguais!");
            puts("Por favor, introduzam tokens diferentes para jogar: ");
            clean_buffer();
        }
        clean_buffer();
    }
    puts("");   
}   