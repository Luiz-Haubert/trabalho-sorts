#pragma once

#include <vector>

std::vector<int> gerarArray(int tamanho);

void imprimirArray(
    const std::vector<int>& vetor
);

std::vector<int> copiarArray(
    const std::vector<int>& vetor
);

long long medirTempo(
    void (*algoritmo)(std::vector<int>&),
    std::vector<int> vetor
);

double calcularMediaTempo(
    void (*algoritmo)(std::vector<int>&),
    int tamanhoVetor,
    int quantidadeTestes
);

double calcularDesvioPadrao(
    void (*algoritmo)(std::vector<int>&),
    int tamanhoVetor,
    int quantidadeTestes
);

std::vector<int> gerarArrayOrdenado(int tamanho);

std::vector<int> gerarArrayInvertido(int tamanho);

std::vector<int> gerarArrayQuaseOrdenado(
    int tamanho,
    int quantidadeTrocas
);

double calcularMediaTempoVetor(
    void (*algoritmo)(std::vector<int>&),
    std::vector<int> vetor,
    int quantidadeTestes
);

struct ResultadoTeste {

    double media;

    double desvioPadrao;

    long long melhorTempo;

    long long piorTempo;

    std::vector<int> melhorVetor;

    std::vector<int> piorVetor;

    double limiteInferior;

    double limiteSuperior;
};

ResultadoTeste executarTestes(
    void (*algoritmo)(std::vector<int>&),
    int tamanhoVetor,
    int quantidadeTestes
);