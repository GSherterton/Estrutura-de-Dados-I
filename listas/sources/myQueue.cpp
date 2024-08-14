#include "myQueue.h"
#include <iostream>

myQueue::myQueue(){
    tamanhoAtual = 0;
    tamanhoMax = 10;
    inicio = 0;
    fim = -1;
}

bool myQueue::vazio(){
    if(tamanhoAtual == 0){
        return true;
    }

    return false;
}

bool myQueue::cheio(){
    if(tamanhoAtual == tamanhoMax){
        return true;
    }

    return false;
}

int myQueue::tamanho(){
    return tamanhoAtual;
}

int myQueue::getInicio(){
    if(vazio()){
        return -1;
    }
    
    return dados[inicio];
}

bool myQueue::inserir(int val){
    if(cheio()){
        return false;
    }

    fim = (fim + 1) % tamanhoMax;
    dados[fim] = val;

    tamanhoAtual++;

    return true;
}

int myQueue::retirar(){
    if(vazio()){
        return -1;
    }

    int aux;
    aux = dados[inicio];
    inicio = (inicio + 1) % tamanhoMax;

    tamanhoAtual--;

    return aux;
}

void myQueue::exibe(){
    if(vazio()){
        return;
    }
    
    cout << "[";

    int i = inicio;
    while(i != fim){
        cout << dados[i] << ", ";
        i = (i + 1) % tamanhoMax;
    }
    cout << dados[i];
    cout << "]\n";
}