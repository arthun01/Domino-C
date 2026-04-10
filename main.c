#include "./lib/domino.c"

void menu(int vez, JogoDominoLista* mesa, Jogador* jogadores){
    printf("- - - MESA:\n");
    if(listaVazia(mesa) == 1){
        printf("- Sem peças na mesa -");
    }else{
        listaImprime(mesa);
    }
    printf("\n- - - JOGADOR %d:\n", vez);
    printarJogador(jogadores, vez - 1);

    int indice;
    do{
        if(indice < 0 && indice > 7){
            printf("Valor inválido, tente outro!!\n");
        }
        printf("Digite o índice da peça que quer jogar: ");
        scanf("%d", &indice);
    }while(indice < 0 && indice > 7);

    int lugar_mesa;
    do{
        if(lugar_mesa != 1 && lugar_mesa != 2){
            printf("Valor inválido, tente outro!!\n");
        }
        printf("[1 esq | 2 dir] Digite onde quer jogar na mesa: ");
        scanf("%d", &lugar_mesa);
    }while(lugar_mesa != 1 && lugar_mesa != 2);
}

int main(void){
    JogoDominoLista* mesa = criarLista();

    int venceu = 0;

    // Criar o array de peças de dominó e já embaralhar
    PedraDomino* baralho = criarBaralho();

    // Inicia os 4 jogadores
    Jogador* jogadores = iniciarJogadores(baralho);

    printarJogadores(jogadores);
    
    while(venceu != 1){
        int vez = 0;

        menu(vez + 1, mesa, jogadores);
        if(vez == 4){
            vez = 0;
        }else{
            vez++;
        }

        venceu++;
    }

    for(int i = 0; i < 4; i++){
        if(jogadores[i].num_pecas == 0){
            printf("Jogador %d - %s ganhou!!", i + 1, jogadores[i].nome);
        }
    }

    return 0;
}