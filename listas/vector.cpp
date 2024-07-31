#include <iostream>
#include "myVector.h"

using namespace std;

int main(){
    myVector lista;
    int pos;

    lista.exibe();
    cout << (lista.vazio() ? "Lista vazia" : "Lista nao vazia") << endl;

    pos = lista.getPos(2);
    cout << ((pos == -1) ? "Elemento nao encontrado" : "Elemento encontrado na posicao " + pos) << endl;
    cout << (lista.inserir(3, 1) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    cout << (lista.inserir(1, 1) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    cout << (lista.inserir(2, 3) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    cout << (lista.inserir(1, 6) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    cout << ((lista.retirar(3) == -1) ? "Nao foi possivel retirar" : "Retirada feita com sucesso") << endl;
    lista.exibe();

    cout << ((lista.setElem(2, 9) == -1) ? "Nao foi possivel mudar o elemento" : "Mudanca feita com sucesso") << endl;
    lista.exibe();

    cout << (lista.inserir(lista.tamanho()+1, 8) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(lista.tamanho()+1, 14) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(lista.tamanho()+1, 2) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << ((lista.retirar(1) == -1) ? "Remocao falhou" : "Remocao feita com sucesso") << endl;
    lista.exibe();
    pos = lista.getPos(2);
    cout << ((pos == -1) ? "Elemento 2 nao encontrado" : "Elemento 2 encontrado na posicao " + to_string(pos)) << endl;
    cout << "Elemento da posicao 4: " << lista.getElem(4) << endl;

    cout << (lista.inserir(lista.tamanho()+1, 3) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(lista.tamanho()+1, 1) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(lista.tamanho()+1, 7) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(lista.tamanho()+1, 5) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(lista.tamanho()+1, 10) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(lista.tamanho()+1, 4) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();
    cout << (lista.inserir(lista.tamanho()+1, 2) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    //cout << (lista.inserir(lista.tamanho()+1, 8) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();


    return 0;
}
