#include "./lib/domino.c"

int main(void){
    // Criar o array de peças de dominó e já embaralhar
    PedraDomino* baralho = criarBaralho();

    // for(int i = 0; i < 28; i++){
    //     printf("[%d][%d]\n", baralho[i].esquerda, baralho[i].direita);
    // }

    // printf("--------\n");

    Jogador* jogadores = iniciarJogadores(baralho);

    printarJogadores(jogadores);

    return 0;
}