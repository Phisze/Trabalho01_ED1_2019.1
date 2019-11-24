#include "fila.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
int i = 0;

void FFVazia(TipoFila *Fila) {
    Fila->Frente = (TipoApontador) malloc(sizeof (TipoCelula));
    Fila->Tras = Fila->Frente;
    Fila->Tam = 0;
    Fila->Frente->Prox = NULL;
}

int VaziaF(TipoFila Fila) {
    return ( Fila.Frente == Fila.Tras);
}

void Enfileira(int nContainers, TipoFila *Fila) {
    Fila->Tras->Prox = (TipoApontador) malloc(sizeof (TipoCelula));

    int n = nContainers;
    Fila->Tras = Fila->Tras->Prox;
    Fila->Tras->Item.nContainers = nContainers;
    Fila->Tras->Item.Chave = i;
    i++;
    Fila->Tras->Item.tempo = 0;
    Fila->Tras->Item.pf0 = malloc(sizeof (TipoPilha));
    FPVazia(Fila->Tras->Item.pf0);
    
    Fila->Tras->Item.pf1 = malloc(sizeof (TipoPilha));
    FPVazia(Fila->Tras->Item.pf1);
    
    Fila->Tras->Item.pf2 = malloc(sizeof (TipoPilha));
    FPVazia(Fila->Tras->Item.pf2);
    
    Fila->Tras->Item.pf3 = malloc(sizeof (TipoPilha));
    FPVazia(Fila->Tras->Item.pf3);
    while (n != 0) {
        if (n != 0) {
            Empilha(Fila->Tras->Item.pf0, 1);
            n--;
        }
        if (n != 0) {
            Empilha(Fila->Tras->Item.pf1, 1);
            n--;
        }
        if (n != 0) {
            Empilha(Fila->Tras->Item.pf2, 1);
            n--;
        }
        if (n != 0) {
            Empilha(Fila->Tras->Item.pf3, 1);
            n--;
        }
    }

    Fila->Tam++;
    Fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *Fila) {
    TipoApontador q;
    if (VaziaF(*Fila)) {
        printf("Erro fila esta vazia\n");
        return;
    }
    q = Fila->Frente;
    Fila->Frente = Fila->Frente->Prox;
    //*Item = Fila->Frente->Item;
    Fila->Tam--;
    free(q);
}