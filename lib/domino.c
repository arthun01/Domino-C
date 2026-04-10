#include "domino.h"

// ** Funções relacionados a Lista Encadeada ** //

// Nome: criarLista
// Descrição: Cria uma nova lista de dominó e retorna um ponteiro para ela
// Retorno: Ponteiro para a nova lista de dominó ou NULL em caso de falha
JogoDominoLista* criarLista(void){
    JogoDominoLista* lista = (JogoDominoLista*)malloc(sizeof(JogoDominoLista));
    if(lista == NULL){
        printf("Erro ao alocar memória para a lista de dominó.\n");
        return NULL;
    }
    lista->inicio = NULL;
    lista->fim = NULL;
    return lista;
}

// Nome: listaVazia
// Descrição: Verifica se a lista de dominós está ou não vazia
// Retorno: 1 se está vazia ou 0 se não está
int listaVazia(JogoDominoLista* lista){
    if(lista == NULL) return 1;
    if(lista->inicio == NULL){
        return 1;
    }else{
        return 0;
    }
}

// Nome: listaInsereInicio
// Descrição: Insere uma peça de dominó no início da lista
// Retorno: Não retorna nada pois muda via endereço de memória diretamente
void listaInsereInicio(JogoDominoLista* lista, int esquerda, int direita){
    PedraDomino* novo = (PedraDomino*)malloc(sizeof(PedraDomino));
    if(novo == NULL){
        printf("Erro em alocação\n");
        return ;
    }

    novo->direita = direita;
    novo->esquerda = esquerda;
    novo->proximo = lista->inicio;

    lista->inicio = novo;

    if(lista->fim == NULL){
        lista->fim = novo;
    }
}

// Nome: listaInsereFim
// Descrição: Insere uma peça de dominó no fim da lista
// Retorno: Não retorna nada pois muda via endereço de memória diretamente
void listaInsereFim(JogoDominoLista* lista, int esquerda, int direita){
    PedraDomino* novo = (PedraDomino*)malloc(sizeof(PedraDomino));
    if(novo == NULL){
        printf("Erro em alocação\n");
        return ;
    }

    novo->direita = direita;
    novo->esquerda = esquerda;
    novo->proximo = NULL;

    if(listaVazia(lista) == 1){
        lista->inicio = novo;
        lista->fim = novo;
    }else{
        lista->fim->proximo = novo;
        lista->fim = novo;
    }
}

// Nome: listaRemoveInicio
// Descrição: Remove uma peça de dominó no início da lista
// Retorno: -1 se a lista estiver vazia ou retorna um array dos valores removidos
void listaRemoveInicio(JogoDominoLista* lista){
    if(listaVazia(lista) == 1){
        printf("Não da para remover pois a lista está vazia\n");
        return ;
    }

    PedraDomino* temp = lista->inicio;
    int valor_dir = temp->direita;
    int valor_esq = temp->esquerda;

    lista->inicio = lista->inicio->proximo;

    if(lista->inicio == NULL){
        lista->fim = NULL;
    }

    free(temp);

    printf("pedra removida: [%d|%d]\n", valor_esq, valor_dir);
}

// Nome: listaRemoveFim
// Descrição: Remove uma peça de dominó no fim da lista
// Retorno: -1 se a lista estiver vazia ou retorna um array dos valores removidos
void listaRemoveFim(JogoDominoLista* lista){
    if(listaVazia(lista) == 1){
        printf("Não da para remover pois a lista está vazia\n");
        return ;
    }

    int valor_dir;
    int valor_esq;

    if(lista->inicio == lista->fim){
        valor_dir = lista->inicio->direita;
        valor_esq = lista->inicio->esquerda;
        free(lista->inicio);
        lista->inicio = NULL;
        lista->fim = NULL;
    }else{
        PedraDomino* p = lista->inicio;
        while(p->proximo != lista->fim){
            p = p->proximo;
        }

        valor_dir = lista->fim->direita;
        valor_esq = lista->fim->esquerda;

        free(lista->fim);
        lista->fim = p;
        lista->fim->proximo = NULL;
    }

    printf("pedra removida: [%d|%d]\n", valor_esq, valor_dir);
}

// Nome: listaImprime
// Descrição: Imprime no terminal a "mesa"
// Retorno: Sem retorno
void listaImprime(JogoDominoLista* lista){
    PedraDomino* p = lista->inicio;

    printf("Está na mesa:\n\n");
    while(p != NULL){
        printf("[%d|%d] ", p->esquerda, p->direita);
        p = p->proximo;
    }
    printf("\n");
}

// Nome: embaralhaBaralhp
// Descrição: Embaralha o baralho a ser jogado
// Retorno: Retorna o array do baralho já embaralhado
PedraDomino* embaralhaBaralho(PedraDomino* baralho){
    srand(time(NULL));

    for(int i = 27; i > 0; i--){
        int j = rand() % (i + 1);

        PedraDomino temp = baralho[i];
        baralho[i] = baralho[j];
        baralho[j] = temp;
    }

    return baralho;
}

// Nome: criarBaralho
// Descrição: Cria o baralho a ser jogado
// Retorno: Retorna um array de 28 espaços que guarda o baralho inteiro
PedraDomino* criarBaralho(void){
    PedraDomino* baralho = malloc(28 * sizeof(PedraDomino));

    if(baralho == NULL){
        printf("Erro de alocação\n");
        return NULL;
    }

    int k = 0;

    for(int i = 0; i <= 6; i++){
        for(int j = i; j <= 6; j++){
            baralho[k].esquerda = i;
            baralho[k].direita = j;
            baralho[k].proximo = NULL;
            k++;
        }
    }

    baralho = embaralhaBaralho(baralho);

    return baralho;
}

Jogador* iniciarJogadores(PedraDomino* baralho){
    // Cria o array de jogadores
    Jogador* jogadores = (Jogador*)malloc(4 * sizeof(Jogador));
    if(jogadores == NULL){
        printf("Erro ao alocar\n");
        return 0;
    }

    // preenche as informações de cada um
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
        jogadores[i].num_pecas = 7;
    }

    return jogadores;
}

void printarJogador(Jogador* jogadores, int n){
    for(int i = 0; i < 7; i++){
        printf("(%d) -> [%d|%d] \n", i, jogadores[n].mao[i].esquerda, jogadores[n].mao[i].direita);
    }
    printf("\n");
}

void printarJogadores(Jogador* jogadores){
    for(int i = 0; i < 4; i++){
        printf("Jogador %d: %s\n", i + 1, jogadores[i].nome);
        printf("Peças na mão: %d\n", jogadores[i].num_pecas);
        // printf("Mão: ");
        // for(int j = 0; j < 7; j++){
        //     printf("[%d|%d] ", jogadores[i].mao[j].esquerda, jogadores[i].mao[j].direita);
        // }
        printf("\n");
    }
}

void viraPedra(PedraDomino* pedra){
    if(pedra == NULL) return;

    int temp = pedra->esquerda;
    pedra->esquerda = pedra->direita;
    pedra->direita = temp;
}

int validarJogada(PedraDomino* pedra, JogoDominoLista* mesa, int escolha){
    if(mesa->inicio == NULL){
        return 1;
    }

    if(escolha == 1){
        if(pedra->direita == mesa->inicio->esquerda){
            return 1;
        }else if(pedra->esquerda == mesa->inicio->esquerda){
            viraPedra(pedra);
            return 1;
        }
    }else if(escolha == 2){
        if(pedra->esquerda == mesa->fim->direita){
            return 1;
        }else if(pedra->direita == mesa->fim->direita){
            viraPedra(pedra);
            return 1;
        }
    }

    return 0;
}