#include <iostream>

class No {
public:
    int dado;
    No* proximo;
    No(int valor) : dado(valor), proximo(NULL) {}
};

class ListaLigada {
private:
    No* cabeca;
public:
    ListaLigada() : cabeca(NULL) {}

    void adicionar(int valor) {
        No* novoNo = new No(valor);
        if (cabeca == NULL) {
            cabeca = novoNo;
        } else {
            No* atual = cabeca;
            while (atual->proximo != NULL) {
                atual = atual->proximo;
            }
            atual->proximo = novoNo;
        }
    }

   
    int tamanho() {
        int tamanho = 0;
        No* atual = cabeca;
        while (atual != NULL) {
            tamanho++;
            atual = atual->proximo;
        }
        return tamanho;
    }

   
    int N_posicao(int posicao) {
        if (posicao < 0) {
            std::cerr << "Posição invalida ." << std::endl;
            return -1; 
        }
        No* atual = cabeca;
        int contador = 0;
        while (atual != NULL) {
            if (contador == posicao) {
                return atual->dado;
            }
            atual = atual->proximo;
            contador++;
        }
        std::cerr << "posiçao não enccontrada." << std::endl;
        return -1; 
    }
};

int main() {
    ListaLigada lista;
    
    lista.adicionar(10);
    lista.adicionar(20);
    lista.adicionar(30);

    std::cout << "Tamanho da lista: " << lista.tamanho() << std::endl;
    
    int posicao = 1;
    std::cout << "Elemento na posição " << posicao << ": " << lista.N_posicao(posicao) << std::endl;
    
    return 0;
}

