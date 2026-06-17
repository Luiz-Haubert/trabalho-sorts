#include <iostream>
#include <iomanip>

#include "Util.h"

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"

using namespace std;
/*
    CONSTROI UM VETOR QUE PRODUZ
    PARTICOES BALANCEADAS PARA O
    QUICK SORT COM PIVO NO FINAL
*/
void construirCasoIdeal(
    vector<int>& vetor,
    int inicio,
    int fim,
    int& valorAtual
) {

    if (inicio > fim) {

        return;
    }

    int meio = inicio + (fim - inicio) / 2;

    construirCasoIdeal(
        vetor,
        inicio,
        meio - 1,
        valorAtual
    );

    construirCasoIdeal(
        vetor,
        meio + 1,
        fim,
        valorAtual
    );

    vetor[fim] = valorAtual;

    valorAtual++;
}

/*
    GERA UM VETOR PARA O MELHOR CASO
    DO QUICK SORT COM PIVO NO FINAL
*/
vector<int> gerarArrayIdealQuick(
    int tamanho
) {

    vector<int> vetor(tamanho);

    int valorAtual = 1;

    construirCasoIdeal(
        vetor,
        0,
        tamanho - 1,
        valorAtual
    );

    return vetor;
}
int main() {

    cout << "\n===== quick sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            quickSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (particoes balanceadas): "
        << calcularMediaTempoVetor(
            quickSort,
            gerarArrayIdealQuick(1000),
            100
        )
        << " ns\n";

    cout << "pior caso (ordenado): "
        << calcularMediaTempoVetor(
            quickSort,
            gerarArrayOrdenado(1000),
            100
        )
        << " ns\n";

    vector<int> vetor = gerarArrayIdealQuick(15);

    for (int x : vetor) {

        cout << x << " ";
    }

    /*bubble sort

    cout << "\n===== bubble sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            bubbleSort,
            10000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (ordenado): "
        << calcularMediaTempoVetor(
            bubbleSort,
            gerarArrayOrdenado(10000),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            bubbleSort,
            gerarArrayInvertido(10000),
            100
        )
        << " ns\n";


    // insertion sort

    cout << "\n===== insertion sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            insertionSort,
            10000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (ordenado): "
        << calcularMediaTempoVetor(
            insertionSort,
            gerarArrayOrdenado(10000),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            insertionSort,
            gerarArrayInvertido(10000),
            100
        )
        << " ns\n";


    // selection sort

    cout << "\n===== selection sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            selectionSort,
            10000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (ordenado): "
        << calcularMediaTempoVetor(
            selectionSort,
            gerarArrayOrdenado(10000),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            selectionSort,
            gerarArrayInvertido(10000),
            100
        )
        << " ns\n";


    // heap sort

    cout << "\n===== heap sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            heapSort,
            10000,
            100
        ).media
        << " ns\n";

    cout << "caso ordenado: "
        << calcularMediaTempoVetor(
            heapSort,
            gerarArrayOrdenado(10000),
            100
        )
        << " ns\n";

    cout << "caso invertido: "
        << calcularMediaTempoVetor(
            heapSort,
            gerarArrayInvertido(10000),
            100
        )
        << " ns\n";


    // shell sort

    cout << "\n===== shell sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            shellSort,
            10000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (quase ordenado): "
        << calcularMediaTempoVetor(
            shellSort,
            gerarArrayQuaseOrdenado(
                10000,
                10
            ),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            shellSort,
            gerarArrayInvertido(10000),
            100
        )
        << " ns\n";


    // merge sort

    cout << "\n===== merge sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            mergeSort,
            10000,
            100
        ).media
        << " ns\n";

    cout << "caso ordenado: "
        << calcularMediaTempoVetor(
            mergeSort,
            gerarArrayOrdenado(10000),
            100
        )
        << " ns\n";

    cout << "caso invertido: "
        << calcularMediaTempoVetor(
            mergeSort,
            gerarArrayInvertido(10000),
            100
        )
        << " ns\n";


    // quick sort

    cout << "\n===== quick sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            quickSort,
            10000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (quase ordenado): "
        << calcularMediaTempoVetor(
            quickSort,
            gerarArrayQuaseOrdenado(
                10000,
                50
            ),
            100
        )
        << " ns\n";

    cout << "pior caso (ordenado): "
        << calcularMediaTempoVetor(
            quickSort,
            gerarArrayOrdenado(10000),
            100
        )
        << " ns\n";*/
    return 0;
}