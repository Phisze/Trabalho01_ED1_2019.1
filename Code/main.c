/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: weverton
 *
 * Created on 28 de Abril de 2019, 12:57
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> 
#include "fila.h"
#include "pilha.h"


#define TEMPO_ESPERA 10

TipoFila *f0;
TipoFila *f1;
TipoFila *f2;
TipoFila *f3;
int cont = 0;
int ct = 0;

/*
 * 
 */
int aletorio(int n) {
    srand(time(NULL));
    return rand() % n;
}

void chegaBarcos() {
    int qntBarcos = aletorio(4);
    printf("Numero de Barcos: %d\n", qntBarcos);
    for (int i = 0; i < qntBarcos; i++) {
        if (cont > 3) {
            cont = 0;
        }
        //Enfilera os Barcos em suas respectivas filas, com um numero de conteiners aleatorio
        if (cont == 0) {
            Enfileira((aletorio(12) + 4), f0);
            cont++;
        } else if (cont == 1) {
            Enfileira((aletorio(12) + 4), f1);
            cont++;
        } else if (cont == 2) {
            Enfileira((aletorio(12) + 4), f2);
            cont++;
        } else if (cont == 3) {
            Enfileira((aletorio(12) + 4), f3);
            cont++;
        }

    }

    // printf("Tamanho da Fila f0: %d\n", f0->Tam);
    //  printf("Tamanho da Fila f1: %d\n", f1->Tam);
    //    printf("Tamanho da Fila f2: %d\n", f2->Tam);
    //printf("Tamanho da Fila f3: %d\n", f3->Tam);
    printf("Tempo medio para o atracamento é de: %d segundos\n", TEMPO_ESPERA);
    fflush(stdout);

    //  printf("Os navios de codigos ");
    fflush(stdout);
    TipoCelula* aux0 = (f0->Frente->Prox);
    TipoCelula* aux1 = (f1->Frente->Prox);
    TipoCelula* aux2 = (f2->Frente->Prox);
    TipoCelula* aux3 = (f3->Frente->Prox);
    // Print codigo e atuliza tempo do navio
    while (aux0 != NULL) {
        printf("cod0: %d ", aux0->Item.Chave);
        fflush(stdout);
        aux0->Item.tempo++;
        aux0 = aux0->Prox;
    }
    printf("\n");
    while (aux1 != NULL) {
        printf("cod1: %d ", aux1->Item.Chave);
        fflush(stdout);
        aux1->Item.tempo++;
        aux1 = aux1->Prox;
    }
    printf("\n");
    while (aux2 != NULL) {
        printf("cod2: %d ", aux2->Item.Chave);
        fflush(stdout);
        aux2->Item.tempo++;
        aux2 = aux2->Prox;
    }
    printf("\n");
    while (aux3 != NULL) {
        printf("cod3: %d ", aux3->Item.Chave);
        fflush(stdout);
        aux3->Item.tempo++;
        aux3 = aux3->Prox;
        
    }
    printf("\n");
}

int carrinho = 0;
int controladorP = 0;
int q = 0;
int contP = 0;
TipoPilha *p0;
TipoPilha *p1;
TipoPilha *p2;
TipoPilha *p3;
TipoPilha *p4;

void travessa() {
    int i = 0;
    int verificador = 0;
    q = 0;
    if (carrinho == 0) {
        printf("O carrinho esta pronto para receber novos conteiners\n");
        while (q < 25 && !((VaziaF(*f0)) && (VaziaF(*f1)) && (VaziaF(*f2)) && (VaziaF(*f3)))) {
            if (verificador == controladorP) {
                i++;
            } else {
                i = 0;
            }
            verificador = controladorP;
            if (i == 100) {
                controladorP = 0;
                //  break;
            }
            if (controladorP == 0) {
                if (contP > 3) {
                    contP = 0;
                }
                //Verifica a fila a ser desenfilerada e seu numero de conteiners total do navio
                if (contP == 0 && f0->Frente->Prox != NULL) {
                    controladorP = f0->Frente->Prox->Item.nContainers;
                } else if (contP == 1 && f1->Frente->Prox != NULL) {
                    controladorP = f1->Frente->Prox->Item.nContainers;
                } else if (contP == 2 && f2->Frente->Prox != NULL) {
                    controladorP = f2->Frente->Prox->Item.nContainers;
                } else if (contP == 3 && f3->Frente->Prox != NULL) {
                    controladorP = f3->Frente->Prox->Item.nContainers;
                } else {
                    break;
                }
            }
            //Verifica se ainda há como desenpilhar e se a espaço para enpilhar
            //Chama a grua para trabalhar
            if (controladorP != 0) {
                if (!(p0->Topo == 5)) {
                    if (contP > 3) {
                        contP = 0;
                    }
                    if (contP == 0) {
                        Grua(p0, f0);
                    } else if (contP == 1) {
                        Grua(p0, f1);
                    } else if (contP == 2) {
                        Grua(p0, f2);
                    } else if (contP == 3) {
                        Grua(p0, f3);
                    }
                }
            }
            if (controladorP != 0) {
                if (!(p1->Topo == 5)) {
                    if (contP > 3) {
                        contP = 0;
                    }
                    if (contP == 0) {
                        Grua(p1, f0);
                    } else if (contP == 1) {
                        Grua(p1, f1);
                    } else if (contP == 2) {
                        Grua(p1, f2);
                    } else if (contP == 3) {
                        Grua(p1, f3);
                    }
                }
            }
            if (controladorP != 0) {
                if (!(p2->Topo == 5)) {
                    if (contP > 3) {
                        contP = 0;
                    }
                    if (contP == 0) {
                        Grua(p2, f0);
                    } else if (contP == 1) {
                        Grua(p2, f1);
                    } else if (contP == 2) {
                        Grua(p2, f2);
                    } else if (contP == 3) {
                        Grua(p2, f3);
                    }
                }
            }
            if (controladorP != 0) {
                if (!(p3->Topo == 5)) {
                    if (contP > 3) {
                        contP = 0;
                    }
                    if (contP == 0) {
                        Grua(p3, f0);
                    } else if (contP == 1) {
                        Grua(p3, f1);
                    } else if (contP == 2) {
                        Grua(p3, f2);
                    } else if (contP == 3) {
                        Grua(p3, f0);
                    }
                }
            }
            if (controladorP != 0) {
                if (!(p4->Topo == 5)) {
                    if (contP > 3) {
                        contP = 0;
                    }
                    if (contP == 0) {
                        Grua(p4, f0);
                    } else if (contP == 1) {
                        Grua(p4, f1);
                    } else if (contP == 2) {
                        Grua(p4, f2);
                    } else if (contP == 3) {
                        Grua(p4, f0);
                    }
                }
            }
            //Tira o navio que está na primeira posição
            if (controladorP == 0) {
                if (contP > 3) {
                    contP = 0;
                }
                if (contP == 0) {
                    contP++;
                    printf("O tempo para este navio desatracar foi de %d segundos\n", f0->Frente->Item.tempo * TEMPO_ESPERA);
                    Desenfileira(f0);
                } else if (contP == 1) {
                    contP++;
                    printf("O tempo para este navio desatracar foi de %d segundos\n", f1->Frente->Item.tempo * TEMPO_ESPERA);
                    Desenfileira(f1);
                } else if (contP == 2) {
                    contP++;
                    printf("O tempo para este navio desatracar foi de %d segundos\n", f2->Frente->Item.tempo * TEMPO_ESPERA);
                    Desenfileira(f2);
                } else if (contP == 3) {
                    contP++;
                    printf("O tempo para este navio desatracar foi de %d segundos\n", f3->Frente->Item.tempo * TEMPO_ESPERA);
                    Desenfileira(f3);
                }
            }
            carrinho++;
        }
    } else {
        carrinho = 0;
        printf("O carrinho esta levando os conteiners\n");
        FPVazia(p0);
        FPVazia(p1);
        FPVazia(p2);
        FPVazia(p3);
        FPVazia(p4);
    }
    printf("Quantidade de Conteiners na travessa 0: %d\n", p0->Topo);
    printf("Quantidade de Conteiners na travessa 1: %d\n", p1->Topo);
    printf("Quantidade de Conteiners na travessa 2: %d\n", p2->Topo);
    printf("Quantidade de Conteiners na travessa 3: %d\n", p3->Topo);
    printf("Quantidade de Conteiners na travessa 4: %d\n", p4->Topo);
    printf("Quantidade total de Conteiners nas travessas %d\n", p0->Topo + p1->Topo + p2->Topo + p3->Topo + p4->Topo);
}

void Grua(TipoPilha *pilha, TipoFila *fila) {
    //Verfica se tem algo a desempilha e se ainda há espaço no carrinho
    //Empilha nos carrinhos e desempilha do navio
    if (fila->Frente->Prox->Item.pf0 != NULL && pilha != NULL && fila != NULL && fila->Frente->Prox->Item.pf0->Topo != 0 && controladorP != 0 && q != 25) {
        Empilha(pilha, fila->Frente->Prox->Item.pf0->Item[fila->Frente->Prox->Item.pf0->Topo - 1]);
        Desempilha(fila->Frente->Prox->Item.pf0);
        controladorP--;
        q++;
    }
    if (fila->Frente->Prox->Item.pf0 != NULL && pilha != NULL && fila != NULL && (fila->Frente->Prox->Item.pf1->Topo != 0) && (controladorP != 0) && (q != 25)) {
        Empilha(pilha, fila->Frente->Prox->Item.pf1->Item[fila->Frente->Prox->Item.pf1->Topo - 1]);
        Desempilha(fila->Frente->Prox->Item.pf1);
        controladorP--;
        q++;
    }
    if (fila->Frente->Prox->Item.pf0 != NULL && pilha != NULL && fila != NULL && fila->Frente->Prox->Item.pf2->Topo != 0 && controladorP != 0 && q != 25) {
        Empilha(pilha, fila->Frente->Prox->Item.pf2->Item[fila->Frente->Prox->Item.pf2->Topo - 1]);
        Desempilha(fila->Frente->Prox->Item.pf2);
        controladorP--;
        q++;
    }
    if (fila->Frente->Prox->Item.pf0 != NULL && pilha != NULL && fila != NULL && fila->Frente->Prox->Item.pf3->Topo != 0 && controladorP != 0 && q != 25) {
        Empilha(pilha, fila->Frente->Prox->Item.pf3->Item[fila->Frente->Prox->Item.pf3->Topo - 1]);
        Desempilha(fila->Frente->Prox->Item.pf3);
        controladorP--;
        q++;
    }
}

int main(int argc, char** argv) {
    //Alocar Fila
    f0 = malloc(sizeof (TipoFila));
    FFVazia(f0);

    f1 = malloc(sizeof (TipoFila));
    FFVazia(f1);

    f2 = malloc(sizeof (TipoFila));
    FFVazia(f2);

    f3 = malloc(sizeof (TipoFila));
    FFVazia(f3);


    //Alocar Pilha
    p0 = malloc(sizeof (TipoPilha));
    FPVazia(p0);

    p1 = malloc(sizeof (TipoPilha));
    FPVazia(p1);

    p2 = malloc(sizeof (TipoPilha));
    FPVazia(p2);

    p3 = malloc(sizeof (TipoPilha));
    FPVazia(p3);

    p4 = malloc(sizeof (TipoPilha));
    FPVazia(p4);

    float tempo_medio = 0;
    //Inicia o Programa
    while (1) {
        printf("Novos Barcos Chegando \n");
        chegaBarcos();
        //Calcula o tempo medio de todas as filas
        if ((f0->Tam + f1->Tam + f2->Tam + f3->Tam) != 0) {
            tempo_medio = (float) ((ct * TEMPO_ESPERA) / (f0->Tam + f1->Tam + f2->Tam + f3->Tam));
        } else {
            tempo_medio = 0;
        }
        printf("Tempo Medio Total: %f\n", tempo_medio);

        //Calcula o tempo medio de sua repectiva fila
        if (f0->Tam != 0) {
            tempo_medio = (float) ((ct * TEMPO_ESPERA) / (f0->Tam));
        } else {
            tempo_medio = 0;
        }
        printf("Tempo Medio F0: %f\n", tempo_medio);

        if (f1->Tam != 0) {
            tempo_medio = (float) ((ct * TEMPO_ESPERA) / (f1->Tam));
        } else {
            tempo_medio = 0;
        }
        printf("Tempo Medio F1: %f\n", tempo_medio);

        if (f2->Tam != 0) {
            tempo_medio = (float) ((ct * TEMPO_ESPERA) / (f2->Tam));
        } else {
            tempo_medio = 0;
        }
        printf("Tempo Medio F2: %f\n", tempo_medio);

        if (f3->Tam != 0) {
            tempo_medio = (float) ((ct * TEMPO_ESPERA) / (f3->Tam));
        } else {
            tempo_medio = 0;
        }
        printf("Tempo Medio F3: %f\n", tempo_medio);
        ct++;
        //Muda as pilhas do navio para a travessa
        travessa();
        //Tempo
        sleep(TEMPO_ESPERA);
    }

    return (EXIT_SUCCESS);
}