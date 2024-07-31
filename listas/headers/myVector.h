#pragma once

using namespace std;

class myVector{
    public:
        myVector();

        bool vazio();                   //retorna se o vector está vazio
        int tamanho();                  //retorna o tamanho atual do vector
        int getPos(int elem);           //retorna a posicao de um elemento
        int getElem(int pos);           //retorna o elemento de uma dada posicao
        bool setElem(int pos, int val); //muda um elemento de uma dada posicao
        bool inserir(int pos, int val); //insere um elemento em uma dada posicao
        int retirar(int pos);           //retorna o elemento retirado
        
        void exibe();                   //exibe todos os elementos da lista

    private:
        int *vec;                       //ponteiro para um array dinamico com os elementos
        int tamanhoAtual;               //tamanho atual da lista
        int tamanhoMax;                 //tamanho atual do array

        bool cheio();                   //retorna se o array esta cheio
        bool aumentarVetor();           //dobra o tamanho do vetor
};