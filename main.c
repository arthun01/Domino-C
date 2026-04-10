#include "./lib/domino.c"

void menu(int vez, JogoDominoLista* mesa, Jogador* jogadores){

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("- - - MESA:\n");
    if(listaVazia(mesa) == 1){
        printf("- Sem peças na mesa -");
    }else{
        listaImprime(mesa);
    }
    printf("\n- - - JOGADOR %d:\n", vez + 1);
    printarJogador(jogadores, vez);

    // jogador escolhe qual peça irá jogar
    int indice;
    do{
        printf("Digite o índice da peça que quer jogar: ");
        scanf("%d", &indice);
        if(indice < 0 || indice > 6){
            printf("Valor inválido, tente outro!!\n");
        }
    }while(indice < 0 || indice > 6);

    // jogador escolhe onde na mesa ele vai jogar 1 sendo na esquerda e 2 na direita
    int lugar_mesa;
    do{
        printf("[1 esq | 2 dir] Digite onde quer jogar na mesa: ");
        scanf("%d", &lugar_mesa);
        if(lugar_mesa != 1 && lugar_mesa != 2){
            printf("Valor inválido, tente outro!!\n");
        }
    }while(lugar_mesa != 1 && lugar_mesa != 2);


    // parte responável por de fato botar a peça na mesa
    PedraDomino pedra = jogadores[vez].mao[indice];

    if(lugar_mesa == 1){
        if(validarJogada(&pedra, mesa, lugar_mesa) == 1){
            listaInsereInicio(mesa, pedra.esquerda, pedra.direita);
            jogadores[vez].mao[indice].direita = -1;
            jogadores[vez].mao[indice].esquerda = -1;
            jogadores[vez].num_pecas -= 1;
        }else{
            printf("Jogada Inválida\n");
        }
    }else if(lugar_mesa == 2){
        if(validarJogada(&pedra, mesa, lugar_mesa) == 1){
            listaInsereFim(mesa, pedra.esquerda, pedra.direita);
            jogadores[vez].mao[indice].direita = -1;
            jogadores[vez].mao[indice].esquerda = -1;
            jogadores[vez].num_pecas -= 1;
        }else{
            printf("Jogada Inválida\n");
        }
    }

    if(jogadores[vez].num_pecas == 0){
        printf("Jogador %d - %s VENCE!!\n", vez + 1, jogadores[vez].nome);
        exit(1);
    }
}

int main(void){
    JogoDominoLista* mesa = criarLista();

    
    // Criar o array de peças de dominó e já embaralhar
    PedraDomino* baralho = criarBaralho();
    
    // Inicia os 4 jogadores
    Jogador* jogadores = iniciarJogadores(baralho);
    
    printarJogadores(jogadores);
    
    int venceu = 0;
    int vez = 0;
    while(venceu != 1){

        menu(vez, mesa, jogadores);
        vez = (vez + 1) % 4;

        // venceu++;
    }

    for(int i = 0; i < 4; i++){
        if(jogadores[i].num_pecas == 0){
            printf("Jogador %d - %s ganhou!!", i + 1, jogadores[i].nome);
        }
    }

    return 0;
}