#include "myVector.h"
#include <iostream>

myVector::myVector(){
    tamanhoAtual = 0;
    tamanhoMax = 1;
    vec = new int[1];
}

bool myVector::vazio(){
    if(tamanhoAtual == 0){
        return true;
    }

    return false;
}

int myVector::tamanho(){
    return tamanhoAtual;
}

int myVector::getPos(int elem){
    for(int i = 0; i < tamanhoAtual; i++){
        if(vec[i] == elem){
            return i+1;
        }
    }

    return -1;
}

int myVector::getElem(int pos){
    if((pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return -1;
    }

    return vec[pos-1];
}

bool myVector::setElem(int pos, int val){
    if((pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return -1;
    }

    vec[pos-1] = val;

    return true;
}

bool myVector::aumentarVetor(){
    int *deletado = vec;

    vec = new int[2*tamanhoMax];

    for(int i = 0; i < tamanhoMax; i++){
        vec[i] = deletado[i];
    }

    tamanhoMax *= 2;

    delete deletado;

    return true;
}

bool myVector::inserir(int pos, int val){
    if((pos > tamanhoAtual+1) || (pos <= 0)){  //checa se a posicao é valida
        return false;
    }

    if(cheio()){ //se o vetor estiver cheio dobra ele de tamanho
        aumentarVetor();
    }

    for(int i = tamanhoAtual; i >= pos; i--){
        vec[i] = vec[i-1];
    }

    vec[pos-1] = val;
    tamanhoAtual++;

    return true;
}

int myVector::retirar(int pos){
    if((pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return -1;
    }

    tamanhoAtual--;

    int aux = vec[pos-1];
    for(int i = pos-1; i < tamanhoAtual; i++){
        vec[i] = vec[i+1];
    }

    return aux;
}

void myVector::exibe(){
    cout << "[";
    for(int i = 0; i < tamanhoAtual; i++){
        cout << vec[i] << (i==tamanhoAtual-1 ? "" : ", ");
    }
    cout << "]\n";
}

bool myVector::cheio(){
    if(tamanhoAtual == tamanhoMax){
        return true;
    }

    return false;
}
