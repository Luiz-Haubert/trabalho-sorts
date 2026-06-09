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
    executa os testes de um algoritmo
    e exibe os resultados formatados
*/
void exibirResultados(const string& nome, void (*algoritmo)(vector<int>&)) { 

    ResultadoTeste resultado =
        executarTestes(
            algoritmo,
            1000,
            100
        );

    cout << "\n========================================\n";
    cout << nome << endl;
    cout << "========================================\n";
    
    //deixa tudo em ms pra ver se é melhor
    double mediaMs =
        resultado.media / 1000000.0;
    double desvioMs =
        resultado.desvioPadrao / 1000000.0;
    double melhorMs =
        resultado.melhorTempo/ 1000000.0;
    double piorMs =
        resultado.piorTempo / 1000000.0;

    cout << "media:          "
        << fixed << setprecision(2)
        << mediaMs
        << " ms\n";

    cout << "desvio padrao:  "
        << desvioMs
        << " ms\n";

    cout << "melhor tempo:   "
        << melhorMs
        << " ms\n";

    cout << "pior tempo:     "
        << piorMs
        << " ms\n";

    cout << "\nprimeiros elementos do melhor vetor:\n";


    for (int i = 0;
        i < min(20, (int)resultado.melhorVetor.size());
        i++) {

        cout << resultado.melhorVetor[i] << " ";
    }

    cout << "\n";

    cout << "\nprimeiros elementos do pior vetor:\n";

    for (int i = 0;
        i < min(20, (int)resultado.piorVetor.size());
        i++) {

        cout << resultado.piorVetor[i] << " ";
    }

    cout << "\n";
}

int main() {

    cout << "========================================\n";
    cout << "teste dos algoritmos de ordenacao\n";
    cout << "========================================\n";

    exibirResultados(
        "bubble sort",
        bubbleSort
    );

    exibirResultados(
        "insertion sort",
        insertionSort
    );

    exibirResultados(
        "selection sort",
        selectionSort
    );

    exibirResultados(
        "heap sort",
        heapSort
    );

    exibirResultados(
        "shell sort",
        shellSort
    );

    exibirResultados(
        "merge sort",
        mergeSort
    );

    exibirResultados(
        "quick sort",
        quickSort
    );

    cout << "\n========================================\n";
    cout << "fim dos testes\n";
    cout << "========================================\n";

    return 0;
}