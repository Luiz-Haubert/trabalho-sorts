#include "QuickSort.h"

using namespace std;

/*
    quick sort

    funcionamento:
    - escolhe um elemento como pivo
    - reorganiza o vetor de forma que:
        elementos menores fiquem a esquerda
        elementos maiores fiquem a direita
    - aplica o mesmo processo recursivamente
      nas duas particoes geradas

    melhor caso:
    O(n log n)

    caso medio:
    O(n log n)

    pior caso:
    O(n²)

    complexidade:
    O(n²)

    memoria adicional:
    O(log n)

    observacao:
    nesta implementacao o ultimo elemento
    e utilizado como pivo
*/

// reorganiza os elementos ao redor do pivo
// retorna a posicao final do pivo
static int particionar(
    vector<int>& vetor,
    int inicio,
    int fim
) {

    // escolhe o ultimo elemento como pivo
    int pivo = vetor[fim];

    // indice do ultimo elemento menor que o pivo
    int i = inicio - 1;

    // percorre o segmento analisado
    for (int j = inicio; j < fim; j++) {

        // move os elementos menores para a esquerda
        if (vetor[j] <= pivo) {

            i++;

            swap(vetor[i], vetor[j]);
        }
    }

    // posiciona o pivo entre as duas particoes
    swap(vetor[i + 1], vetor[fim]);

    return i + 1;
}

// aplica o quick sort recursivamente
static void quickSortRecursivo(
    vector<int>& vetor,
    int inicio,
    int fim
) {

    // continua apenas se houver mais de um elemento
    if (inicio < fim) {

        // encontra a posicao correta do pivo
        int indicePivo =
            particionar(vetor, inicio, fim);

        // ordena a particao esquerda
        quickSortRecursivo(
            vetor,
            inicio,
            indicePivo - 1
        );

        // ordena a particao direita
        quickSortRecursivo(
            vetor,
            indicePivo + 1,
            fim
        );
    }
}

// funcao principal chamada pelo programa
void quickSort(vector<int>& vetor) {

    if (vetor.empty()) {
        return;
    }

    quickSortRecursivo(
        vetor,
        0,
        vetor.size() - 1
    );
}