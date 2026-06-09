#include "BubbleSort.h"


/*
    bubble sort

    funcionamento:
    - compara pares de elementos vizinhos
    - troca os elementos quando estao fora de ordem
    - a cada passada o maior valor restante vai para o final do vetor
    - termina quando o vetor esta ordenado

    melhor caso:
    vetor ja ordenado
    O(n)

    caso medio:
    O(n²)

    pior caso:
	O(n²)
    vetor em ordem inversa

    complexidade O(n²)

    memoria adicional:
    O(1)
*/
using namespace std;

void bubbleSort(vector<int>& vetor) {

    // quantidade total de elementos
    int n = vetor.size();

    // indica se alguma troca ocorreu durante a passada
    bool trocou;

    // cada repeticao posiciona um elemento na posicao correta
    for (int i = 0; i < n - 1; i++) {

        trocou = false;

        // percorre apenas a parte ainda nao ordenada
        // o final do vetor ja esta ordenado pelas passadas anteriores
        for (int j = 0; j < n - i - 1; j++) {

            // verifica se os elementos estao fora de ordem
            if (vetor[j] > vetor[j + 1]) {

                // realiza a troca para aproximar o vetor da ordenacao
                swap(vetor[j], vetor[j + 1]);

                trocou = true;
            }
        }

        // se nenhuma troca aconteceu significa que
        // o vetor ja esta completamente ordenado
        if (!trocou)
            break;
    }
}