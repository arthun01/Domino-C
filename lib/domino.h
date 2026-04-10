#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef DOMINO_H
#define DOMINO_H

// * Estruturas * //
// Pedra
typedef struct Pedra_Domino{
    int esquerda;
    int direita;
    struct Pedra_Domino* proximo;
} PedraDomino;

// Lista (mesa)
typedef struct Jogo_DominoLista {
    PedraDomino* inicio;
    PedraDomino* fim;
} JogoDominoLista;

// Jogador
typedef struct jogador{
    PedraDomino mao[7];
    char nome[20];
    int num_pecas;
} Jogador;

// * Protótipos de funções * //
// MENU
void menu(int vez, JogoDominoLista* mesa, Jogador* jogadores);

// Lista (mesa)
JogoDominoLista* criarLista(void);
int listaVazia(JogoDominoLista* lista);

void listaInsereInicio(JogoDominoLista* lista, int esquerda, int direita);
void listaInsereFim(JogoDominoLista* lista, int esquerda, int direita);

void listaRemoveInicio(JogoDominoLista* lista);
void listaRemoveFim(JogoDominoLista* lista);
void listaLibera(JogoDominoLista* lista);

void listaImprime(JogoDominoLista* lista);

// Baralho
PedraDomino* embaralhaBaralho(PedraDomino* baralho);

PedraDomino* criarBaralho(void);
void viraPedra(PedraDomino* pedra);
int validarJogada(PedraDomino* pedra, JogoDominoLista* mesa, int escolha);

// Jogadores
Jogador* iniciarJogadores(PedraDomino* baralho);
void printarJogadores(Jogador* jogadores);

void printarJogador(Jogador* jogadores, int n);

// MENU
void menu(int vez, JogoDominoLista* mesa, Jogador* jogadores);

#endif