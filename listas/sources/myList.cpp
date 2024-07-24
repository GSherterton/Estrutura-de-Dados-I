#include "myList.h"
#include <iostream>

myList::myList(){
    tamanhoAtual = 0;
}

bool myList::vazio(){
    if(tamanhoAtual == 0){
        return true;
    }

    return false;
}

int myList::tamanho(){
    return tamanhoAtual;
}

int myList::getPos(int elem){
    No aux = *cabeca;
    int cont = 1;

    if(vazio()){
        return -1;
    }

    while(aux.proximo != NULL){ //itera sobre a lista ate achar o elemento procurado ou chegar no final dela
        if(aux.conteudo == elem){
            return cont;
        }
        cont++;
        aux = *aux.proximo;
    }

    return -1;
}

int myList::getElem(int pos){
    if(vazio() || (pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return -1;
    }

    No aux = *cabeca;
    int cont = 1;

    while(cont < pos){ //itera sobre a lista ate chegar na posicao desejada
        cont++;
        aux = *aux.proximo;
    }

    return aux.conteudo;
}

bool myList::setElem(int pos, int val){
    if(vazio() || (pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return false;
    }

    No aux = *cabeca;
    int cont = 1;
    
    while(cont < pos){ //itera sobre a lista ate chegar na posicao desejada
        cont++;
        aux = *aux.proximo;
    }

    aux.conteudo = val;

    return true;
}

void myList::inserirNoInicio(int val){
    No novo = No();
    novo.conteudo = val;

    *novo.proximo = *cabeca;
    *cabeca = novo;
}

void myList::inserirNoMeio(int pos, int val){
    pos--; //transforma a posicao para o valor anterior ao que se deseja
    No aux = *cabeca;
    No novo = No();
    novo.conteudo = val;

    int cont = 1;
    
    while(cont < pos){ //acha a posicao anterior a qual se deseja inserir
        cont++;
        aux = *aux.proximo;
    }

    novo.proximo = aux.proximo;
    *aux.proximo = novo;
}

bool myList::inserir(int pos, int val){
    if((pos > tamanhoAtual+1) || (pos <= 0)){  //checa se a posicao é valida
        return false;
    }

    if(pos == 1){
        inserirNoInicio(val);
    }else{
        inserirNoMeio(pos, val);
    }

    tamanhoAtual++;

    return true;
}

int myList::retirar(int pos){
    if((pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return -1;
    }

    pos--;  //transforma a posicao para o valor anterior ao que se deseja

    No aux = *cabeca;
    int cont = 1;
    No removido;
    
    while(cont < pos){ //acha a posicao a qual se deseja retirar
        cont++;
        aux = *aux.proximo;
    }

    removido = *aux.proximo;
    aux.proximo = (*aux.proximo).proximo;


    tamanhoAtual--;

    return removido.conteudo;
}

void myList::exibe(){
    int cont = 1;

    No aux = *cabeca;

    cout << "[";
    while(cont <= tamanhoAtual){
        cout << aux.conteudo << ((cont == (tamanhoAtual)) ? "" : ", ");
        aux = *aux.proximo;
        cont++;
    }
    cout << "]\n";
}
