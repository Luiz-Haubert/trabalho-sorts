#include "Util.h"

#include <iostream>
#include <random>
#include <chrono>
#include <cmath>

using namespace std;
using namespace std::chrono;

vector<int> gerarArray(int tamanho) {

    // dispositivo utilizado para gerar sementes aleatorias
    random_device rd;

    // gerador de numeros pseudoaleatorios
    mt19937 gen(rd());

    // define o intervalo dos valores gerados
    uniform_int_distribution<> dist(1, 1000);

    // cria o vetor com o tamanho informado
    vector<int> vetor(tamanho);

    // preenche cada posicao do vetor
    for (int i = 0; i < tamanho; i++) {

        vetor[i] = dist(gen);
    }

    return vetor;
}


void imprimirArray(const vector<int>& vetor) {

    for (int numero : vetor) {

        cout << numero << " ";
    }

    cout << endl;
}


vector<int> copiarArray(const vector<int>& vetor) {

    return vetor;
}

long long medirTempo(
    void (*algoritmo)(vector<int>&),
    vector<int> vetor
) {

    // registra o instante inicial
    auto inicio = high_resolution_clock::now();

    // executa o algoritmo recebido
    algoritmo(vetor);

    // registra o instante final
    auto fim = high_resolution_clock::now();

    // retorna o tempo em nanossegundos
    return duration_cast<nanoseconds>(
        fim - inicio
    ).count();
}


double calcularMediaTempo(
    void (*algoritmo)(vector<int>&),
    int tamanhoVetor,
    int quantidadeTestes
) {

    long long somaTempos = 0;

    // executa o algoritmo varias vezes
    for (int i = 0; i < quantidadeTestes; i++) {

        // gera um novo vetor aleatorio
        vector<int> vetor =
            gerarArray(tamanhoVetor);

        // soma o tempo da execucao atual
        somaTempos +=
            medirTempo(algoritmo, vetor);
    }

    // calcula a media dos tempos
    return (double)somaTempos /
        quantidadeTestes;
}


double calcularDesvioPadrao(
    void (*algoritmo)(vector<int>&),
    int tamanhoVetor,
    int quantidadeTestes
) {

    // armazena os tempos coletados
    vector<long long> tempos;

    long long somaTempos = 0;

    // executa os testes e registra os tempos
    for (int i = 0; i < quantidadeTestes; i++) {

        vector<int> vetor =
            gerarArray(tamanhoVetor);

        long long tempo =
            medirTempo(algoritmo, vetor);

        tempos.push_back(tempo);

        somaTempos += tempo;
    }

    // calcula a media dos tempos
    double media =
        (double)somaTempos /
        quantidadeTestes;

    double somaQuadrados = 0;

    // calcula a soma dos desvios ao quadrado
    for (long long tempo : tempos) {

        somaQuadrados +=
            pow(tempo - media, 2);
    }

    // aplica a formula do desvio padrao
    return sqrt(
        somaQuadrados /
        quantidadeTestes
    );
}

ResultadoTeste executarTestes(
    void (*algoritmo)(vector<int>&),
    int tamanhoVetor,
    int quantidadeTestes
) {

    ResultadoTeste resultado;

    vector<long long> tempos;

    long long somaTempos = 0;

    resultado.melhorTempo =
        numeric_limits<long long>::max();

    resultado.piorTempo = 0;

    // executa todos os testes
    for (int i = 0; i < quantidadeTestes; i++) {

        vector<int> vetor =
            gerarArray(tamanhoVetor);

        long long tempo =
            medirTempo(algoritmo, vetor);

        tempos.push_back(tempo);

        somaTempos += tempo;

        // atualiza o melhor tempo
        if (tempo < resultado.melhorTempo) {

            resultado.melhorTempo = tempo;

            resultado.melhorVetor = vetor;
        }

        // atualiza o pior tempo
        if (tempo > resultado.piorTempo) {

            resultado.piorTempo = tempo;

			resultado.piorVetor = vetor;
        }
    }

    // calcula a media
    resultado.media =
        (double)somaTempos /
        quantidadeTestes;

    double somaQuadrados = 0;

    // calcula os desvios ao quadrado
    for (long long tempo : tempos) {

        somaQuadrados +=
            pow(
                tempo - resultado.media,
                2
            );
    }

    // calcula o desvio padrao
    resultado.desvioPadrao =
        sqrt(
            somaQuadrados /
            quantidadeTestes
        );

    resultado.limiteInferior =
        resultado.media -
        resultado.desvioPadrao;

    resultado.limiteSuperior =
        resultado.media +
        resultado.desvioPadrao;

    return resultado;
}