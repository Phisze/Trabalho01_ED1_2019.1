/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   pilha.h
 * Author: wever
 *
 * Created on 28 de Abril de 2019, 12:59
 */

#ifndef PILHA_H
#define PILHA_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
#define MAXTAM 5

typedef int TipoApontadorP;
typedef int TipoChave;

typedef struct {
    int Chave;
} TipoItemP;

typedef struct {
    int Item[MAXTAM];
    TipoApontadorP Topo;
} TipoPilha;

void FPVazia(TipoPilha *Pilha);

int VaziaP(TipoPilha Pilha);

void Empilha(TipoPilha *Pilha, int x);

void Desempilha(TipoPilha *Pilha);

int Tamanho(TipoPilha Pilha);
#endif /* PILHA_H */

