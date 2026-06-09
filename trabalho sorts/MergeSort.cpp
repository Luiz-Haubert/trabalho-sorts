#include "MergeSort.h"

using namespace std;

/*
    merge sort

    funcionamento:
    - divide o vetor em duas partes menores
    - continua dividindo ate restar apenas um elemento
    - junta as partes de forma ordenada
    - repete o processo ate reconstruir todo o vetor

    melhor caso:
    O(n log n)

    caso medio:
    O(n log n)

    pior caso:
    O(n log n)

    complexidade:
    O(n log n)

    memoria adicional:
    O(n)
*/

// junta dois segmentos ordenados em um unico segmento ordenado
static void merge(vector<int>& vetor, int inicio, int meio, int fim) {

    // calcula o tamanho dos vetores auxiliares
    int tamanhoEsquerda = meio - inicio + 1;
    int tamanhoDireita = fim - meio;

    // cria vetores auxiliares
    vector<int> esquerda(tamanhoEsquerda);
    vector<int> direita(tamanhoDireita);

    // copia os elementos da metade esquerda
    for (int i = 0; i < tamanhoEsquerda; i++) {
        esquerda[i] = vetor[inicio + i];
    }

    // copia os elementos da metade direita
    for (int i = 0; i < tamanhoDireita; i++) {
        direita[i] = vetor[meio + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = inicio;

    // compara os elementos dos dois vetores auxiliares
    // e insere o menor deles no vetor original
    while (i < tamanhoEsquerda && j < tamanhoDireita) {

        if (esquerda[i] <= direita[j]) {
            vetor[k] = esquerda[i];
            i++;
        }
        else {
            vetor[k] = direita[j];
            j++;
        }

        k++;
    }

    // copia os elementos restantes da esquerda
    while (i < tamanhoEsquerda) {
        vetor[k] = esquerda[i];
        i++;
        k++;
    }

    // copia os elementos restantes da direita
    while (j < tamanhoDireita) {
        vetor[k] = direita[j];
        j++;
        k++;
    }
}

// divide o vetor recursivamente em partes menores
static void mergeSortRecursivo(
    vector<int>& vetor,
    int inicio,
    int fim
) {

    // encerra quando restar apenas um elemento
    if (inicio >= fim) {
        return;
    }

    // encontra o meio do segmento atual
    int meio = inicio + (fim - inicio) / 2;

    // ordena a metade esquerda
    mergeSortRecursivo(vetor, inicio, meio);

    // ordena a metade direita
    mergeSortRecursivo(vetor, meio + 1, fim);

    // junta as duas metades ordenadas
    merge(vetor, inicio, meio, fim);
}

// funcao principal chamada pelo programa
void mergeSort(vector<int>& vetor) {

    if (vetor.empty()) {
        return;
    }

    mergeSortRecursivo(
        vetor,
        0,
        vetor.size() - 1
    );
}