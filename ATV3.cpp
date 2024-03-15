#include <iostream>
#include <algorithm>

class Conjunto {
private:
    int elementos[20];
    int tamanho;

public:
    // Construtor para criar um conjunto vazio
    Conjunto() : tamanho(0) {}

    // Método para adicionar um elemento ao conjunto
    void adicionarElemento(int elemento) {
        if (tamanho < 20) {
            elementos[tamanho++] = elemento;
        } else {
            std::cout << "Tamanho máximo do conjunto atingido!" << std::endl;
        }
    }

    // Método para ler os dados de um conjunto
    void lerConjunto() {
        std::cout << "Digite o tamanho do conjunto: ";
        std::cin >> tamanho;

        std::cout << "Digite os elementos do conjunto: ";
        for (int i = 0; i < tamanho; ++i) {
            std::cin >> elementos[i];
        }
    }

    // Método para fazer a união de dois conjuntos
    Conjunto uniao(const Conjunto& outroConjunto) const {
        Conjunto resultado = *this;

        for (int i = 0; i < outroConjunto.tamanho; ++i) {
            resultado.adicionarElemento(outroConjunto.elementos[i]);
        }

        return resultado;
    }

    // Método para fazer a interseção de dois conjuntos
    Conjunto intersecao(const Conjunto& outroConjunto) const {
        Conjunto resultado;

        for (int i = 0; i < tamanho; ++i) {
            for (int j = 0; j < outroConjunto.tamanho; ++j) {
                if (elementos[i] == outroConjunto.elementos[j]) {
                    resultado.adicionarElemento(elementos[i]);
                    break;
                }
            }
        }

        return resultado;
    }

    // Método para imprimir um conjunto
    void imprimir() const {
        std::cout << "{ ";
        for (int i = 0; i < tamanho; ++i) {
            std::cout << elementos[i] << " ";
        }
        std::cout << "}" << std::endl;
    }
};

int main() {
    Conjunto conjunto1, conjunto2;

    std::cout << "Conjunto 1:" << std::endl;
    conjunto1.lerConjunto();

    std::cout << "Conjunto 2:" << std::endl;
    conjunto2.lerConjunto();

    Conjunto uniao = conjunto1.uniao(conjunto2);
    std::cout << "União dos conjuntos: ";
    uniao.imprimir();

    Conjunto intersecao = conjunto1.intersecao(conjunto2);
    std::cout << "Interseção dos conjuntos: ";
    intersecao.imprimir();

    return 0;
}

