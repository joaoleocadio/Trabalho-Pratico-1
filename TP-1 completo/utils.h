/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utils.h
 * Author: João Leocádio
 *
 * Created on 20 de Novembro de 2017, 20:21
 */

#ifndef UTILS_H
#define UTILS_H

#define TAMANHO 10
#define TAMTOKENS 2

void jogo(char mat[][TAMANHO], char tokens[]);
void apresentacao();
void clean_buffer();
void preencherMatriz();
void imprimirMatriz();
void escolherTokens();
int checkResult(char mat[TAMANHO][TAMANHO], char tokens[], int l, char c);


#endif /* UTILS_H */

