#include "./lib/domino.c"

int main(void){
    // Criar o array de peças de dominó
    PedraDomino* baralho = criarBaralho();

    for(int i = 0; i < 28; i++){
        printf("[%d][%d]\n", baralho[i].esquerda, baralho[i].direita);
    }

    printf("--------\n");

    Jogador* jogadores = (Jogador*)malloc(4 * sizeof(Jogador));
    if(jogadores == NULL){
        printf("Erro ao alocar\n");
        return 0;
    }

    int k = 0;
    for(int i = 0; i < 4; i++){
        char nome_prov[20];
        printf("Digite seu nome Jogador %d: ", i + 1);
        scanf("%19[^\n]%*c", nome_prov);


        strcpy(jogadores[i].nome, nome_prov);
        for(int j = 0; j < 7; j++){
            jogadores[i].mao[j] = baralho[k];
            jogadores[i].mao[j].proximo = NULL;
            k++;
        }
    }

    for(int i = 0; i < 4; i++){
        printf("Jogador %d: %s\n", i + 1, jogadores[i].nome);
        printf("Mão: ");
        for(int j = 0; j < 7; j++){
            printf("[%d|%d] ", jogadores[i].mao[j].esquerda, jogadores[i].mao[j].direita);
        }
        printf("\n\n");
    }

    return 0;
}