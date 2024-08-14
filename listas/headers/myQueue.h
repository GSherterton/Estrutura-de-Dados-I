#pragma once

using namespace std;

class myQueue{
    public:
        myQueue();

        bool vazio();                   //retorna se a fila está vazia
        bool cheio();                   //retorna se o array esta cheio
        int tamanho();                  //retorna o tamanho atual da fila
        int getInicio();                //retorna o elemento do inicio da fila
        bool inserir(int val);          //insere um elemento no final da fila
        int retirar();                  //retorna o elemento retirado do começo da fila
        
        void exibe();                   //exibe todos os elementos da fila

    private:
        int dados[10];                  //array com os elementos da fila
        int inicio;                     //indice do primeiro elemento da fila
        int fim;                        //indice do ultimo elemento da fila
        int tamanhoAtual;               //tamanho atual da fila
        int tamanhoMax;                 //tamanho atual do array
};