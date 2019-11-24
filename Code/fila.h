/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   fila.h
 * Author: wever
 *
 * Created on 28 de Abril de 2019, 12:59
 */

#ifndef FILA_H
#define FILA_H

#include "pilha.h"


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif
typedef struct TipoCelula *TipoApontador;

typedef struct TipoItem {
    int Chave;
    int nContainers;
    int tempo;
    TipoPilha *pf0;
    TipoPilha *pf1;
    TipoPilha *pf2;
    TipoPilha *pf3;
} TipoItem;

typedef struct TipoCelula {
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;

typedef struct TipoFila {
    TipoApontador Frente, Tras;
    int Tam;
} TipoFila;

void FFVazia(TipoFila *Fila);

int VaziaF(TipoFila Fila);

void Enfileira(int x, TipoFila *Fila);

void Desenfileira(TipoFila *Fila);
#endif /* FILA_H */

