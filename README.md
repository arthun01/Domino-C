# 🎲 Dominó em C

Um jogo de dominó interativo executado via terminal, desenvolvido em linguagem C. Este projeto utiliza o conceito de **Listas Encadeadas** para simular a mesa do jogo, permitindo a inserção de pedras nas extremidades e a gestão completa das rodadas.

## 🤖​ Funcionalidades
- **Multiplayer Local**: Suporte para 4 jogadores no mesmo terminal.
- **Estruturas de Dados**: Uso de Listas Encadeadas dinâmicas para gerenciar as peças que estão atualmente jogadas na mesa.
- **Validação de Jogadas**: O sistema impede movimentos inválidos e inverte as peças automaticamente quando necessário para encaixar na mesa (ex: converte `[2|4]` para `[4|2]` se a extremidade exigir).
- **Geração Aleatória**: O baralho de 28 pedras é gerado e embaralhado de forma aleatória a cada nova partida.
- **Menu Interativo**: Interface simples no terminal para visualização da mesa, da mão do jogador atual e escolha de onde jogar a pedra (esquerda ou direita).

## 📁 Estrutura do Projeto
- `main.c`: Arquivo principal que inicializa o jogo, os jogadores e controla o loop da partida.
- `lib/domino.h`: Arquivo de cabeçalho contendo a definição das estruturas (`PedraDomino`, `JogoDominoLista`, `Jogador`) e os protótipos de funções.
- `lib/domino.c`: Implementação de todas as funções, incluindo a lógica da lista encadeada (mesa), validações e o menu interativo.
- `01.input`: Arquivo de texto contendo nomes de jogadores predefinidos para facilitar a automação de testes.
- `.gitignore`: Configuração para ignorar arquivos binários compilações (como `*.out` e `*.bin`).

## 🚀 Como executar

1. Clone o repositório para a sua máquina:
```bash
git clone https://github.com/arthun01/Domino-C.git
cd Domino-C

2. Compile o código usando o gcc:
```bash
gcc main.c -o main
```

3. Rode o jogo:
```bash
./main
```

## 🎮 Como jogar
O jogo começa distribuindo 7 peças para cada um dos 4 jogadores.

Na sua vez, a tela exibirá as peças atualmente na mesa e as peças na sua mão com seus respectivos índices numéricos.

Digite o índice da peça que deseja jogar. (Caso não tenha uma peça compatível, digite -1 para passar a vez).

Em seguida, escolha a posição na mesa: digite 1 para colocar na extremidade esquerda ou 2 para a extremidade direita.

O primeiro jogador a ficar sem nenhuma peça na mão vence a partida!

👤 Autor
Desenvolvido por Arthur Ramos Vieira