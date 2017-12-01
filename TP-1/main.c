/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: João Leocádio
 *
 * Created on 29 de Novembro de 2017, 18:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define TAMANHO 10
#define TAMTOKENS 2

/*
 *Trabalho prático 1 (Jogo 3 em linha) 
 */
int main(int argc, char** argv)
{
    char mat[TAMANHO][TAMANHO]; //matriz principal (tabuleiro)
    char tokens[TAMTOKENS]; // vetor para guardar os tokens selecionados pelos players (2)
    
    apresentacao();
    escolherTokens(tokens);
    preencherMatriz(mat);
    imprimirMatriz(mat);
}

