#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef DOMINO_H
#define DOMINO_H

// * Estruturas * //


typedef struct Pedra_Domino{
    int esquerda;
    int direita;
    struct Pedra_Domino* proximo;
} PedraDomino;


typedef struct Jogo_DominoLista {
    PedraDomino* inicio;
    PedraDomino* fim;
} JogoDominoLista;

typedef struct jogador{
    PedraDomino mao[7];
    char nome[20];
} Jogador;

// * Protótipos de funções * //
JogoDominoLista* criarLista(void);
int listaVazia(JogoDominoLista* lista);

void listaInsereInicio(JogoDominoLista* lista, int esquerda, int direita);
void listaInsereFim(JogoDominoLista* lista, int esquerda, int direita);

void listaRemoveInicio(JogoDominoLista* lista);
void listaRemoveFim(JogoDominoLista* lista);

void listaImprime(JogoDominoLista* lista);
PedraDomino* embaralhaBaralho(PedraDomino* baralho);

PedraDomino* criarBaralho(void);

Jogador* criarJogador(PedraDomino* baralho, int n);

#endif