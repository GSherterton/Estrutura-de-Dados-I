#include <iostream>
#include "myQueue.h"

using namespace std;

int main(){
    myQueue lista;

    lista.exibe();
    cout << (lista.vazio() ? "Fila vazia" : "Fila nao vazia") << endl;


    cout << ((lista.getInicio() == -1) ? "Fila vazia" : ("Elemento " + to_string(lista.getInicio()) + " encontrado no comeco")) << endl;
    
    cout << (lista.inserir(1) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    cout << ((lista.getInicio() == -1) ? "Fila vazia" : ("Elemento " + to_string(lista.getInicio()) + " encontrado no comeco")) << endl;
    cout << (lista.inserir(3) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    cout << (lista.inserir(6) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    cout << ((lista.retirar() == -1) ? "Nao foi possivel retirar" : "Retirada feita com sucesso") << endl;
    lista.exibe();

    cout << ((lista.retirar() == -1) ? "Remocao falhou" : "Remocao feita com sucesso") << endl;
    lista.exibe();
    cout << ((lista.getInicio() == -1) ? "Fila vazia" : ("Elemento " + to_string(lista.getInicio()) + " encontrado no comeco")) << endl;

    cout << (lista.inserir(1) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(3) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(7) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(5) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(10) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    cout << (lista.inserir(4) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();
    cout << (lista.inserir(2) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();
    cout << (lista.inserir(8) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();
    cout << (lista.inserir(9) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();
    cout << (lista.inserir(15) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();
    cout << ((lista.retirar() == -1) ? "Remocao falhou" : "Remocao feita com sucesso") << endl;
    lista.exibe();
    cout << ((lista.retirar() == -1) ? "Remocao falhou" : "Remocao feita com sucesso") << endl;
    lista.exibe();
    cout << (lista.inserir(3) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();
    cout << (lista.inserir(7) ? "Insercao feita com sucesso" : "Nao foi possivel inserir") << endl;
    lista.exibe();

    return 0;
}
