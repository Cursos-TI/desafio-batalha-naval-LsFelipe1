#include <stdio.h>

// Dimensões fixas do tabuleiro (10x10)
#define TAM_TABULEIRO 10
// Tamanho fixo dos navios (3 posições)
#define TAM_NAVIO 3
// Representação de água no tabuleiro
#define AGUA 0
// Representação de navio no tabuleiro
#define NAVIO 3

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Percorre todas as linhas do tabuleiro
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        // Percorre todas as colunas do tabuleiro
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA; // Define cada posição como água
        }
    }
}

// Função para validar posicionamento de navio horizontal ou vertical
int validarNavioReto(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int horizontal) {
    // Verifica se a coordenada inicial está dentro dos limites do tabuleiro
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        return 0; // Coordenada inválida
    }

    // Para navio horizontal
    if (horizontal) {
        // Verifica se o navio ultrapassa o limite de colunas
        if (coluna + TAM_NAVIO > TAM_TABULEIRO) {
            return 0; // Não cabe no tabuleiro
        }
        // Verifica se há sobreposição com outros navios
        for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
            if (tabuleiro[linha][j] == NAVIO) {
                return 0; // Sobreposição detectada
            }
        }
    } else { // Para navio vertical
        // Verifica se o navio ultrapassa o limite de linhas
        if (linha + TAM_NAVIO > TAM_TABULEIRO) {
            return 0; // Não cabe no tabuleiro
        }
        // Verifica se há sobreposição com outros navios
        for (int i = linha; i < linha + TAM_NAVIO; i++) {
            if (tabuleiro[i][coluna] == NAVIO) {
                return 0; // Sobreposição detectada
            }
        }
    }
    return 1; // Posição válida
}

// Função para validar posicionamento de navio diagonal
int validarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
    // Verifica se a coordenada inicial está dentro dos limites do tabuleiro
    if (linha < 0 || linha >= TAM_TABULEIRO || coluna < 0 || coluna >= TAM_TABULEIRO) {
        return 0; // Coordenada inválida
    }

    // Para diagonal crescente (ex: linha aumenta, coluna aumenta)
    if (direcao == 1) {
        // Verifica se o navio ultrapassa os limites
        if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) {
            return 0; // Não cabe no tabuleiro
        }
        // Verifica se há sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna + i] == NAVIO) {
                return 0; // Sobreposição detectada
            }
        }
    } else { // Para diagonal decrescente (ex: linha aumenta, coluna diminui)
        // Verifica se o navio ultrapassa os limites
        if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO + 1 < 0) {
            return 0; // Não cabe no tabuleiro
        }
        // Verifica se há sobreposição
        for (int i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna - i] == NAVIO) {
                return 0; // Sobreposição detectada
            }
        }
    }
    return 1; // Posição válida
}

// Função para posicionar navio horizontal ou vertical
void posicionarNavioReto(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int horizontal) {
    // Posiciona navio horizontal
    if (horizontal) {
        for (int j = coluna; j < coluna + TAM_NAVIO; j++) {
            tabuleiro[linha][j] = NAVIO; // Marca a posição como navio
        }
    } else { // Posiciona navio vertical
        for (int i = linha; i < linha + TAM_NAVIO; i++) {
            tabuleiro[i][coluna] = NAVIO; // Marca a posição como navio
        }
    }
}

// Função para posicionar navio diagonal
void posicionarNavioDiagonal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna, int direcao) {
    // Para diagonal crescente
    if (direcao == 1) {
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna + i] = NAVIO; // Marca a posição como navio
        }
    } else { // Para diagonal decrescente
        for (int i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linha + i][coluna - i] = NAVIO; // Marca a posição como navio
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Imprime cabeçalho com números de colunas
    printf("\n  ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    // Imprime cada linha do tabuleiro com seus valores
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%d ", i); // Imprime número da linha
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime valor da célula
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro como matriz 10x10
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Coordenadas e orientação dos navios retos
    int linhaHorizontal = 1; // Navio horizontal na linha 1, coluna 2
    int colunaHorizontal = 2;
    int linhaVertical = 6; // Navio vertical na linha 6, coluna 1
    int colunaVertical = 1;

    // Coordenadas e direção dos navios diagonais
    int linhaDiagonal1 = 0; // Diagonal crescente a partir de (0,0)
    int colunaDiagonal1 = 0;
    int linhaDiagonal2 = 2; // Diagonal decrescente a partir de (2,9)
    int colunaDiagonal2 = 9;

    // Valida e posiciona o navio horizontal
    if (validarNavioReto(tabuleiro, linhaHorizontal, colunaHorizontal, 1)) {
        posicionarNavioReto(tabuleiro, linhaHorizontal, colunaHorizontal, 1);
    } else {
        printf("Erro: Posição inválida para o navio horizontal!\n");
        return 1;
    }

    // Valida e posiciona o navio vertical
    if (validarNavioReto(tabuleiro, linhaVertical, colunaVertical, 0)) {
        posicionarNavioReto(tabuleiro, linhaVertical, colunaVertical, 0);
    } else {
        printf("Erro: Posição inválida para o navio vertical!\n");
        return 1;
    }

    // Valida e posiciona o navio diagonal crescente
    if (validarNavioDiagonal(tabuleiro, linhaDiagonal1, colunaDiagonal1, 1)) {
        posicionarNavioDiagonal(tabuleiro, linhaDiagonal1, colunaDiagonal1, 1);
    } else {
        printf("Erro: Posição inválida para o navio diagonal crescente!\n");
        return 1;
    }

    // Valida e posiciona o navio diagonal decrescente
    if (validarNavioDiagonal(tabuleiro, linhaDiagonal2, colunaDiagonal2, 0)) {
        posicionarNavioDiagonal(tabuleiro, linhaDiagonal2, colunaDiagonal2, 0);
    } else {
        printf("Erro: Posição inválida para o navio diagonal decrescente!\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios posicionados
    printf("Tabuleiro com quatro navios posicionados:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
