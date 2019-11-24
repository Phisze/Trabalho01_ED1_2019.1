#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

void FPVazia(TipoPilha *Pilha) {
    Pilha->Topo = 0;
}

int VaziaP(TipoPilha Pilha) {
    return (Pilha.Topo == 0);
}

void Empilha(TipoPilha *Pilha, int x) {
    if (Pilha->Topo == MAXTAM) {
      //  printf("Erro : pilha esta cheia\n");
    } else {
        Pilha->Topo++;
        Pilha->Item[Pilha->Topo - 1] = x;
    }
}

void Desempilha(TipoPilha *Pilha) {
    if (VaziaP(*Pilha)) {
        printf("Erro : pilha esta vazia\n");
    } else {
//        *Item = Pilha->Item[Pilha->Topo - 1];
        Pilha->Topo--;
    }
}

int Tamanho(TipoPilha Pilha) {
    return ( Pilha .Topo);
}