#include <stdio.h>
#include "utils.h"
#include <string.h>

#define TAMANHO 10
#define TAMTOKENS 2
#define N_PLAYERS 25

void clean_buffer() {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void preencherMatriz(char mat[TAMANHO][TAMANHO]) 
{
    int i, j;
    int num = '0';
    char abc = 'A';

    mat[1][1] = " "; //posição [1][1] da matriz preenchida com espaço em branco;

    for (i = 1; i < TAMANHO; ++i) //preenche a 1ª linha com letras (A a I)
    {
        mat[0][i] = abc;
        ++abc;
    }

    for (i = 1; i < TAMANHO; ++i) //preencher a 1ª coluna com números (1 a 9)
    {
        mat[i][0] = num + i;
    }

    for (i = 1; i < TAMANHO; ++i) //preencher o resto da matriz com '-'
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
        puts(" "); // para a matriz ficar quadrada
    }
}

int lerString(char *string, int max) {
    if (fgets(string, max, stdin) != NULL) {
        int tamanho = strlen(string) - 1;
        if (string[tamanho] == '\n') {
            string[tamanho] = '\0';
        } else {
            clean_buffer();
        }
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
    {                                           //Inserir o nome do jogador 1
        printf("Jogador nº %d\n", i + 1);
        printf("Introduza o seu nome: ");
        lerString(jogador1, N_PLAYERS);
    }

    for (i = 0; i < 1; ++i) 
    {                                           //Inserir o nome do jogador 2
        printf("Jogador nº %d\n", i + 2);
        printf("Introduza o seu nome: ");
        lerString(jogador2, N_PLAYERS);
    }

    for (i = 0; i < (TAMTOKENS-1); ++i)
    {                                                   //Escolhe token para cada jogador
        printf("%s escolha o seu token: ", jogador1);
        scanf("%c", &tokens[0]);    //guardar no indice 0 do vetor
        clean_buffer();
        printf("%s escolha o seu token: ", jogador2);
        scanf("%c", &tokens[1]);    //guardar no indice 1 do vetor

        if (tokens[0] == tokens[1])     //comparar as posições e decrementar ate que escolham 
        {                               //tokens diferente
            i -= 1;
            puts("Os tokens são iguais!");
            puts("Por favor, introduzam tokens diferentes para jogar: ");
            clean_buffer();
        }
        clean_buffer();
    }
    puts("");
}

void jogo(char mat[][TAMANHO], char tokens[]) 
{
    int l, i, k = 0;
    char c;
    int jogador = 1;
    int vitoria = 0;
    int contar = 0;

    for (i = 0; i < 81; ++i) //81 = nº de jogadas 9 x 9
    {
        ++contar;
        while (jogador == 1)
        {
            printf("jogador %d Introduza a linha: ", jogador);
            scanf("%d", &l);
            printf("jogador %d Introduza a coluna: ", jogador);
            clean_buffer();
            scanf("%c", &c);
            clean_buffer();
            if (c == 90 && l == 0)  //Z = 90 ASCII
            {                                               //jogador 1 a desistir
                printf("Jogador %d desistiu!! ", jogador);
                ++k;
                break;
            }
            c = c - 64; //conversão de letras
            if (mat[l][c] == '-')
            {                                               //verificar se é possivel jogar e tambem ganhar
                mat[l][c] = tokens[0];                      //função checkResult
                vitoria = checkResult(mat,tokens, l, c);
            } 
            else if (mat[l][c] != '-') 
            {
                while (mat[l][c] != '-' || mat[l][c] == tokens[0] || mat[l][c] == tokens[1]) 
                {
                    puts("Posição ocupada ou existente!\n");
                    printf("jogador %d Introduza a linha: ", jogador);
                    scanf("%d", &l);
                    printf("jogador %d Introduza a coluna: ", jogador);
                    clean_buffer();
                    scanf("%c", &c);
                    if (c == 90 && l == 0)  //http://www.asciitable.com/
                    {                                                   // desistir se a posicção ja estiver ocupada
                        printf("Jogador %d desistiu!! Nº de jogadas: %d\n ", jogador, contar);
                        ++k;
                        break;
                    }
                    c = c - 64; //converter os caracteres Tabela ASCII | http://www.asciitable.com/
                    clean_buffer();
                    if (mat[l][c] == '-') 
                    {
                        puts("Posição aceite! ");
                        mat[l][c] = tokens[0];
                        vitoria = checkResult(mat,tokens, l, c);
                        imprimirMatriz(mat);
                        break;
                    }
                    if (vitoria == 1)
                    {
                        break;
                    }
                }
            }
            if (k > 0)
            {               //sair para o anterior loop
                break;
            }
            if (vitoria > 0)
            {
                imprimirMatriz(mat);
                break;
            }
            imprimirMatriz(mat);
            ++jogador;
            ++i;
        }

        if (k > 0) 
        {               // sair totalmente
            break;
        }
        
        if (vitoria > 0)
        {
            imprimirMatriz(mat);
            printf("Jogador %d ganhou!! Nº de jogadas: %d\n ", jogador, contar);
            break;
        }

        while (jogador == 2) 
        {
            printf("jogador %d Introduza a linha: ", jogador);
            scanf("%d", &l);
            printf("jogador %d Introduza a coluna: ", jogador);
            clean_buffer();
            scanf("%c", &c);
            clean_buffer();
            if (c == 90 && l == 0)  //Z = 90 | ASCII http://www.asciitable.com/
            {
                printf("Jogador %d desistiu!! Nº de jogadas : %d\n ", jogador, contar);
                ++k;
                break;
            }
            c = c - 64; //conversão de letras
            if (mat[l][c] == '-')
            {
                mat[l][c] = tokens[1];
                vitoria=checkResult(mat,tokens, l, c);
            }
            else if (mat[l][c] != '-') 
            {
                while (mat[l][c] != '-' || mat[l][c] == tokens[0] || mat[l][c] == tokens[1])
                {
                    puts("Posição ocupada ou inexistente!\n");
                    printf("jogador %d Introduza a linha: ", jogador);
                    scanf("%d", &l);
                    printf("jogador %d Introduza a coluna: ", jogador);
                    clean_buffer();
                    scanf("%c", &c);
                    if (c == 90 && l == 0)   //http://www.asciitable.com/
                    {
                        printf("Jogador %d desistiu!! Nº de jogadas: %d\n ", jogador, contar);
                        ++k;
                        break;
                    }
                    c = c - 64;
                    clean_buffer();
                    if (mat[l][c] == '-') 
                    {
                        mat[l][c] = tokens[1];
                        vitoria=checkResult(mat,tokens, l, c);
                        imprimirMatriz(mat);
                        break;
                    }
                    if (vitoria > 0)
                    {
                        imprimirMatriz(mat);
                        break;
                    }
                }
            } 
            if (k > 0) 
            {
                break;
            }
            imprimirMatriz(mat);
            if (vitoria > 0)
            {
                imprimirMatriz(mat);
                break;
            }
            --jogador; //decrementa o jogador para continuar o ciclo
            ++i;
        }
        if (k > 0) 
        {
            break;
        }
        if (vitoria > 0)
        {
            imprimirMatriz(mat);
            printf("Jogador %d ganhou!! Nº de jogadas: %d\n ", jogador, contar);
            break;
        }    
        //if
    }
}

int checkResult(char mat[TAMANHO][TAMANHO], char tokens[], int l, char c)
{
    int i, j;                       
                                        //https://stackoverflow.com/questions/25289526/connect-4-check-if-player-wins
    
    // verificar posições horizontais
    for (i = 1; i < TAMANHO; ++i)
    {
        for (j = 1; j < TAMANHO - 2; ++j)
        {
            if (mat[i][j] != '-' && mat[i][j] == mat[i][j + 1] && mat[i][j] == mat[i][j + 2])
            {
                return 1;
            }
        }
    }

    // verificar posicões verticais
    for (i = 1; i < TAMANHO - 2; ++i)
    {
        for (j = 1; j < TAMANHO; ++j) 
        {
            if (mat[i][j] != '-' && mat[i][j] == mat[i + 1][j] && mat[i][j] == mat[i + 2][j])
            {
                return 1;
            }

        }
    }

    // verificar a diagonal direita
    for (i = 1; i < TAMANHO - 2; ++i)
    {
        for (j = 1; j < TAMANHO - 2; ++j)
        {
            if (mat[i][j] != '-' && mat[i][j] == mat[i + 1][j + 1] && mat[i][j] == mat[i + 2][j + 2]) 
            {
                return 1;
            }
        }
    }

    // verificar a diagonal esquerda
    for (i = 1; i < TAMANHO - 2; ++i)
    {
        for (j = 1; j < TAMANHO - 2; ++j) 
        {
            if (mat[i][j] != '-' && mat[i][j] == mat[i + 1][j - 1] && mat[i][j] == mat[i + 2][j - 2]) 
            {
                return 1;
            }
        }
    }  
    return 0;
}