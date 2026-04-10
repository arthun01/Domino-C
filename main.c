// Autor: Arthur Ramos Vieira

#include "./lib/domino.c"

int main(void){
    int ans;
    do{
        // Cria a lista encadeada de pedras na mesa, começando a mesa com 0 pedras
        JogoDominoLista* mesa = criarLista();
        
        // Criar o array de peças de dominó e já embaralhar
        PedraDomino* baralho = criarBaralho();
        
        // Inicializa os 4 jogadores
        Jogador* jogadores = iniciarJogadores(baralho);
        
        // printarJogadores(jogadores);
        
        int venceu = 0;
        int vez = 0;
        while(venceu != 1){
            menu(vez, mesa, jogadores);
            vez = (vez + 1) % 4;
        }

        for(int i = 0; i < 4; i++){
            if(jogadores[i].num_pecas == 0){
                printf("Jogador %d - %s ganhou!!", i + 1, jogadores[i].nome);
            }
        }

        // liberar memórias alocadas
        listaLibera(mesa);
        free(baralho);
        free(jogadores);

        printf("Quer jogar dominó de novo?\n[1] Sim\n[2] Não | Resposta: ");
        scanf("%d", &ans);

    }while(ans != 1 || ans != 2);

    return 0;
}