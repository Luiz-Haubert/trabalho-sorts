#include "InsertionSort.h"

using namespace std;

/*
    insertion sort

    funcionamento:
    - percorre o vetor da esquerda para a direita
    - considera que a parte esquerda ja esta ordenada
    - insere cada novo elemento na posicao correta
    - desloca os elementos maiores para abrir espaco

    melhor caso:
    vetor ja ordenado
    O(n)

    caso medio:
    O(n²)

    pior caso:
    vetor em ordem inversa
    O(n²)

    complexidade:
    O(n²)

    memoria adicional:
    O(1)
*/

void insertionSort(vector<int>& vetor) {

    int tamanho = vetor.size();

    // percorre cada elemento a partir da segunda posicao
    for (int i = 1; i < tamanho; i++) {

        // armazena o valor que sera inserido
        int chave = vetor[i];

        // inicia na posicao anterior
        int j = i - 1;

        /*desloca todos os elementos maiores
        uma posicao para a direita

        isso cria um espaco para inserir
        a chave na posicao correta*/
        while (j >= 0 && vetor[j] > chave) {

            vetor[j + 1] = vetor[j];

            j--;
        }

        // insere a chave na posicao correta
        vetor[j + 1] = chave;
    }
}