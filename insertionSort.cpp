#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

struct Instance{
    string name;
    vector<int> vec;
    void read(){
        ifstream fp;

        fp.open(name);

        if(!fp.is_open()){
            cout << "Nao foi possivel abrir o arquivo\n";
            return;
        }

        int tamanho;
        fp >> tamanho;

        int aux;
        for(int i = 0; i < tamanho; i++){
            fp >> aux;
            vec.push_back(aux);
        }
    }

    void print(){
        for(int i = 0; i < vec.size(); i++){
            cout << vec[i] << " ";
        }cout << "\n";
    }
};

void insertionSort(vector<int>& vec){
    int tamanho = vec.size();

    int aux, i, j;
    for(i = 1; i < tamanho; i++){ //itera sobre o vetor
        aux = vec[i];
        for(j = i-1; j >= 0; j--){ //ordena o vetor antes do elemento da iteração
            if(vec[j] > aux){
                vec[j+1] = vec[j];
            }else{
                break;
            }
        }

        vec[j+1] = aux;
    }
}

int main(int argc, char** argv){
    if(argc < 2){
        cout << "Missing instance name\n";

        exit(1);
    }

    Instance instance;
    instance.name = argv[1];
    instance.read();

    //contagem de tempo
    clock_t start, end;
    double tempo = 0;

    //debug
    //instance.print();

    start = clock(); //inicia o contador de tempo

    insertionSort(instance.vec);

    end = clock(); //pega o tempo final

    //debug
    //instance.print();

    tempo = (double)(end - start) / (double)(CLOCKS_PER_SEC); //realiza o cálculo do tempo gasto pela ordenação

    cout << instance.name << ": " << tempo << endl; //printa a instancia lida e o tempo que demorou para resolver

    return 0;
}