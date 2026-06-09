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

int main() {

    // bubble sort

    cout << "\n===== bubble sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            bubbleSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (ordenado): "
        << calcularMediaTempoVetor(
            bubbleSort,
            gerarArrayOrdenado(1000),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            bubbleSort,
            gerarArrayInvertido(1000),
            100
        )
        << " ns\n";


    // insertion sort

    cout << "\n===== insertion sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            insertionSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (ordenado): "
        << calcularMediaTempoVetor(
            insertionSort,
            gerarArrayOrdenado(1000),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            insertionSort,
            gerarArrayInvertido(1000),
            100
        )
        << " ns\n";


    // selection sort

    cout << "\n===== selection sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            selectionSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (ordenado): "
        << calcularMediaTempoVetor(
            selectionSort,
            gerarArrayOrdenado(1000),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            selectionSort,
            gerarArrayInvertido(1000),
            100
        )
        << " ns\n";


    // heap sort

    cout << "\n===== heap sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            heapSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "caso ordenado: "
        << calcularMediaTempoVetor(
            heapSort,
            gerarArrayOrdenado(1000),
            100
        )
        << " ns\n";

    cout << "caso invertido: "
        << calcularMediaTempoVetor(
            heapSort,
            gerarArrayInvertido(1000),
            100
        )
        << " ns\n";


    // shell sort

    cout << "\n===== shell sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            shellSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (quase ordenado): "
        << calcularMediaTempoVetor(
            shellSort,
            gerarArrayQuaseOrdenado(
                1000,
                10
            ),
            100
        )
        << " ns\n";

    cout << "pior caso (invertido): "
        << calcularMediaTempoVetor(
            shellSort,
            gerarArrayInvertido(1000),
            100
        )
        << " ns\n";


    // merge sort

    cout << "\n===== merge sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            mergeSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "caso ordenado: "
        << calcularMediaTempoVetor(
            mergeSort,
            gerarArrayOrdenado(1000),
            100
        )
        << " ns\n";

    cout << "caso invertido: "
        << calcularMediaTempoVetor(
            mergeSort,
            gerarArrayInvertido(1000),
            100
        )
        << " ns\n";


    // quick sort

    cout << "\n===== quick sort =====\n";

    cout << "caso medio: "
        << executarTestes(
            quickSort,
            1000,
            100
        ).media
        << " ns\n";

    cout << "melhor caso (quase ordenado): "
        << calcularMediaTempoVetor(
            quickSort,
            gerarArrayQuaseOrdenado(
                1000,
                50
            ),
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
    return 0;
}