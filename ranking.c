#include <stdio.h>

#define NUM_JOGADORES 12

// Função para exibir a lista de pontuações
void exibirLista(int pontuacoes[], int n, const char* mensagem) {
    printf("%s\n", mensagem);
    for (int i = 0; i < n; i++) {
        printf("%d ", pontuacoes[i]);
    }
    printf("\n\n");
}

// Bubble Sort - ordem decrescente
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // ordem decrescente
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort - ordem decrescente
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < chave) { // ordem decrescente
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = chave;
    }
}

// Selection Sort - ordem decrescente
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int indiceMax = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[indiceMax]) { // busca o maior para colocar na frente
                indiceMax = j;
            }
        }
        if (indiceMax != i) {
            int temp = arr[i];
            arr[i] = arr[indiceMax];
            arr[indiceMax] = temp;
        }
    }
}

int main() {
    // Lista desordenada de pontuações de 12 jogadores
    int pontuacoes[NUM_JOGADORES] = {85, 92, 78, 96, 88, 73, 99, 81, 90, 87, 76, 94};

    // Cópias para aplicar os diferentes algoritmos
    int bubble[NUM_JOGADORES], insertion[NUM_JOGADORES], selection[NUM_JOGADORES];

    // Copiando os dados
    for (int i = 0; i < NUM_JOGADORES; i++) {
        bubble[i] = insertion[i] = selection[i] = pontuacoes[i];
    }

    // Exibindo a lista original
    exibirLista(pontuacoes, NUM_JOGADORES, "Lista original de pontuações:");

    // Aplicando os três algoritmos (todos ordenam em ordem decrescente)
    bubbleSort(bubble, NUM_JOGADORES);
    insertionSort(insertion, NUM_JOGADORES);
    selectionSort(selection, NUM_JOGADORES);

    // Exibindo a lista ordenada (usamos qualquer uma, ex: bubble)
    exibirLista(bubble, NUM_JOGADORES, "Lista ordenada em ordem decrescente:");

    // Posição do jogador com maior pontuação (será o primeiro, índice 0)
    printf("O jogador com a maior pontuação ficou na posição 1.\n");

    return 0;
}