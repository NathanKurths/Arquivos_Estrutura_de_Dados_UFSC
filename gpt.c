#include <stdio.h>

#define MAX_SIZE 1000 // Defina o tamanho máximo do vetor

int main() {
    double vetor[MAX_SIZE]; // Vetor para armazenar os valores do arquivo
    int tamanho = 0; // Variável para controlar o tamanho do vetor

    FILE *arquivo = fopen("teste_le_val.txt", "r"); // Abre o arquivo para leitura

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Lê os valores do arquivo e os armazena no vetor
    while (fscanf(arquivo, "%lf", &vetor[tamanho]) == 1) {
        tamanho++;
        if (tamanho >= MAX_SIZE) {
            printf("O vetor está cheio. Aumente o tamanho máximo.\n");
            break;
        }
    }

    fclose(arquivo); // Fecha o arquivo

    // Imprime os valores do vetor
    for (int i = 0; i < tamanho; i++) {
        printf("%.2lf ", vetor[i]);
    }
    printf("\n");

    return 0;
}