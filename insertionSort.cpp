#include <iostream>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

struct Instance{
    string name;
    vector<int> vec;
};

void insertionSort(vector<int> vec){
    for(int i = 0; i < 10000000; i++){

    }
}

int main(int argc, char** argv){
    Instance instance;
    instance.name = argv[1];

    //contagem de tempo
    clock_t start, end;
    double tempo = 0;

    start = clock(); //inicia o contador de tempo

    insertionSort(instance.vec);

    end = clock(); //pega o tempo final

    tempo = (double)(end - start) / (double)(CLOCKS_PER_SEC); //realiza o cálculo do tempo gasto pela ordenação

    cout << instance.name << ": " << tempo << endl; //printa a instancia lida e o tempo que demorou para resolver

    return 0;
}