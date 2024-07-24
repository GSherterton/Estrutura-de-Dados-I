#include <iostream>
#include "myVector.h"
#include "myList.h"

using namespace std;

int main(){
    myList lista;

    lista.exibe();
    cout << lista.vazio() << endl;

    cout << lista.getPos(2) << endl;
    lista.inserir(3, 1);
    lista.exibe();

    lista.inserir(1, 1);
    lista.exibe();

    lista.inserir(2, 3);
    lista.exibe();

    lista.inserir(1, 6);
    lista.exibe();

    lista.retirar(3);
    lista.exibe();

    lista.setElem(2, 9);
    lista.exibe();

    lista.inserir(lista.tamanho()+1, 8);
    lista.inserir(lista.tamanho()+1, 14);
    lista.inserir(lista.tamanho()+1, 2);
    lista.exibe();


    return 0;
}
