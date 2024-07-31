#include "mySinglyList.h"
#include <iostream>

mySinglyList::mySinglyList(){
    tamanhoAtual = 0;
    cabeca = nullptr;
}

bool mySinglyList::vazio(){
    if(tamanhoAtual == 0){
        return true;
    }

    return false;
}

int mySinglyList::tamanho(){
    return tamanhoAtual;
}

int mySinglyList::getPos(int elem){
    SinglyNo *aux = cabeca;
    int cont = 1;

    if(vazio()){
        return -1;
    }

    while(aux != nullptr){ //itera sobre a lista ate achar o elemento procurado ou chegar SinglyNo final dela
        if(aux->conteudo == elem){
            return cont;
        }
        cont++;
        aux = aux->proximo;
    }

    return -1;
}

int mySinglyList::getElem(int pos){
    if(vazio() || (pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return -1;
    }

    SinglyNo *aux = cabeca;
    int cont = 1;

    while(cont < pos){ //itera sobre a lista ate chegar na posicao desejada
        cont++;
        aux = aux->proximo;
    }

    return aux->conteudo;
}

bool mySinglyList::setElem(int pos, int val){
    if(vazio() || (pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return false;
    }

    SinglyNo *aux = cabeca;
    int cont = 1;
    
    while(cont < pos){ //itera sobre a lista ate chegar na posicao desejada
        cont++;
        aux = aux->proximo;
    }

    aux->conteudo = val;

    return true;
}

void mySinglyList::inserirNoInicio(int val){
    SinglyNo *novoNo = new SinglyNo();
    novoNo->conteudo = val;

    novoNo->proximo = cabeca;
    cabeca = novoNo;
}

void mySinglyList::inserirNoMeio(int pos, int val){
    pos--; //transforma a posicao para o valor anterior ao que se deseja
    SinglyNo *aux = cabeca;
    SinglyNo *novoNo = new SinglyNo();
    novoNo->conteudo = val;

    int cont = 1;
    
    while(cont < pos){ //acha a posicao anterior a qual se deseja inserir
        cont++;
        aux = aux->proximo;
    }

    novoNo->proximo = aux->proximo;
    aux->proximo = novoNo;
}

bool mySinglyList::inserir(int pos, int val){
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

int mySinglyList::retirarNoInicio(){
    int dado;

    SinglyNo *removido = cabeca;
    cabeca = cabeca->proximo;

    dado = removido->conteudo;
    delete removido;

    return dado;
}

int mySinglyList::retirarNoMeio(int pos){
    pos--;  //transforma a posicao para o valor anterior ao que se deseja

    SinglyNo *aux = cabeca;
    int cont = 1;
    SinglyNo *removido;
    int dado;
    
    while(cont < pos){ //acha a posicao a qual se deseja retirar
        cont++;
        aux = aux->proximo;
    }

    removido = aux->proximo;
    aux->proximo = removido->proximo;

    dado = removido->conteudo;
    delete removido;

    return dado;
}

int mySinglyList::retirar(int pos){
    if((pos > tamanhoAtual) || (pos <= 0)){  //checa se a posicao é valida
        return -1;
    }

    int dado;

    if(pos == 1){
        dado = retirarNoInicio();
    }else{
        dado = retirarNoMeio(pos);
    }

    tamanhoAtual--;
    
    return dado;
}

void mySinglyList::exibe(){
    int cont = 1;

    SinglyNo *aux = cabeca;

    cout << "[";
    while(cont <= tamanhoAtual){
        cout << aux->conteudo << ((cont == (tamanhoAtual)) ? "" : ", ");
        aux = aux->proximo;
        cont++;
    }
    cout << "]\n";
}
