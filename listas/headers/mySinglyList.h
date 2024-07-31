#pragma once
#include "SinglyNo.h"

using namespace std;

class mySinglyList{
    public:
        mySinglyList();

        bool vazio();                   //retorna se o vector está vazio
        int tamanho();                  //retorna o tamanho atual do vector
        int getPos(int elem);           //retorna a posicao de um elemento
        int getElem(int pos);           //retorna o elemento de uma dada posicao
        bool setElem(int pos, int val); //muda um elemento de uma dada posicao
        bool inserir(int pos, int val); //insere um elemento em uma dada posicao
        int retirar(int pos);           //retorna o elemento retirado
        
        void exibe();                   //exibe todos os elementos da lista

    private:
        SinglyNo *cabeca;               //array com os elementos
        int tamanhoAtual;               //tamanho atual da lista

        void inserirNoInicio(int val);
        void inserirNoMeio(int pos, int val);
        int retirarNoInicio();
        int retirarNoMeio(int pos);

};