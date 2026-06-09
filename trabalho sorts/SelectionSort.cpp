#include "SelectionSort.h"

using namespace std;

/*
    selection sort

    funcionamento:
    - procura o menor elemento da parte nao ordenada
    - troca esse elemento com a primeira posicao disponivel
    - repete o processo ate ordenar todo o vetor

    melhor caso:
    O(n²)

    caso medio:
    O(n²)

    pior caso:
    O(n²)

    complexidade:
    O(n²)

    memoria adicional:
    O(1)
*/

void selectionSort(vector<int>& vetor) {

    int tamanho = vetor.size();

    // percorre cada posicao do vetor
    for (int i = 0; i < tamanho - 1; i++) {

        // assume inicialmente que o menor elemento
        // esta na posicao atual
        int indiceMenor = i;

        // procura o menor elemento da parte nao ordenada
        for (int j = i + 1; j < tamanho; j++) {

            if (vetor[j] < vetor[indiceMenor]) {

                indiceMenor = j;
            }
        }

        // coloca o menor elemento encontrado
        // na posicao correta
        if (indiceMenor != i) {

            swap(vetor[i], vetor[indiceMenor]);
        }
    }
}