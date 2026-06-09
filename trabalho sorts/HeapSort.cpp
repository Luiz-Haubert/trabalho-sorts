#include "HeapSort.h"

using namespace std;

/*
    heap sort

    funcionamento:
    - transforma o vetor em uma heap maxima
    - o maior elemento fica na raiz da heap
    - troca a raiz com o ultimo elemento
    - reduz o tamanho da heap
    - reorganiza a heap novamente
    - repete ate que todo o vetor esteja ordenado

    melhor caso:
    O(n log n)

    caso medio:
    O(n log n)

    pior caso:
    O(n log n)

    complexidade:
    O(n log n)

    memoria adicional:
    O(1)
*/

// reorganiza a heap para garantir que o maior elemento
// fique na raiz da subarvore analisada
void heapify(vector<int>& vetor, int tamanhoHeap, int raiz) {

    // assume inicialmente que a raiz e o maior elemento
    int maior = raiz;

    // calcula os indices dos filhos
    int esquerda = 2 * raiz + 1;
    int direita = 2 * raiz + 2;

    // verifica se o filho esquerdo existe e é maior
    if (esquerda < tamanhoHeap &&
        vetor[esquerda] > vetor[maior]) {

        maior = esquerda;
    }

    // verifica se o filho direito existe e é maior
    if (direita < tamanhoHeap &&
        vetor[direita] > vetor[maior]) {

        maior = direita;
    }

    // se a raiz nao for o maior elemento
    // realiza a troca e continua reorganizando
    if (maior != raiz) {

        swap(vetor[raiz], vetor[maior]);

        heapify(vetor, tamanhoHeap, maior);
    }
}

/*
    algoritmo principal

    primeiro constroi uma heap maxima

    depois move repetidamente o maior elemento
    para o final do vetor
*/
void heapSort(vector<int>& vetor) {

    int tamanho = vetor.size();

    // constroi a heap maxima
    // comeca do ultimo no interno ate a raiz
    for (int i = tamanho / 2 - 1; i >= 0; i--) {

        heapify(vetor, tamanho, i);
    }

    // extrai os elementos da heap um a um
    for (int i = tamanho - 1; i > 0; i--) {

        // move o maior elemento para sua posicao final
        swap(vetor[0], vetor[i]);

        // reorganiza a heap restante
        heapify(vetor, i, 0);
    }
}