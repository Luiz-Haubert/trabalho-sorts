#include "ShellSort.h"

using namespace std;

/*
    shell sort

    funcionamento:
    - melhora o insertion sort utilizando intervalos
    - inicialmente compara elementos distantes
    - reduz gradualmente o intervalo entre comparacoes
    - quando o intervalo chega a 1, executa um insertion sort
    - como os elementos ja estao parcialmente ordenados,
      o insertion sort final torna-se mais eficiente

    melhor caso:
    O(n log n)

    caso medio:
    aproximadamente O(n^1.5)

    pior caso:
    O(n²)

    complexidade:
    depende da sequencia de intervalos utilizada

    memoria adicional:
    O(1)
*/

void shellSort(vector<int>& vetor) {

    int tamanho = vetor.size();

    // define o intervalo inicial como metade do vetor
    for (int gap = tamanho / 2; gap > 0; gap /= 2) {

        /*
            realiza um insertion sort considerando
            apenas elementos separados pelo gap atual
        */
        for (int i = gap; i < tamanho; i++) {

            // armazena o elemento atual
            int valorAtual = vetor[i];

            int j = i;

            /*
                desloca os elementos maiores
                para abrir espaco para o valor atual
            */
            while (j >= gap && vetor[j - gap] > valorAtual) {

                vetor[j] = vetor[j - gap];

                j -= gap;
            }

            // insere o valor na posicao correta
            vetor[j] = valorAtual;
        }
    }
}