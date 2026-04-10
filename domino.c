#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Pedra_Domino{
    int esquerda;
    int direita;
    struct Pedra_Domino* proximo;
} PedraDomino;

typedef struct Jogo_DominoLista {
    PedraDomino* inicio;
    PedraDomino* fim;
} JogoDominoLista;

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



int main(void){
    // Criar o array de peças de dominó
    PedraDomino* baralho = criarBaralho();

    for(int i = 0; i < 28; i++){
        printf("[%d][%d]\n", baralho[i].esquerda, baralho[i].direita);
    }

    return 0;
}

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

