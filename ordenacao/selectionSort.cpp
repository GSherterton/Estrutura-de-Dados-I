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

void troca(int &a, int &b){
    int aux;
    aux = a;
    a = b;
    b = aux;
}

void selectionSort(vector<int>& vec){
    int tamanho = vec.size()-1;

    int *menor;
    int i, j;
    for(i = 0; i < tamanho; i++){ //itera sobre o vetor
        menor = &vec[i];
        for(j = i+1; j <= tamanho; j++){ //procura o menor elemento a partir da posicao i
            if(vec[j] < *menor){
                menor = &vec[j];
            }
        }

        troca(vec[i], *menor); //passa o elemento de menor e da iteração atual
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

    selectionSort(instance.vec);

    end = clock(); //pega o tempo final

    //debug
    //instance.print();

    tempo = (double)(end - start) / (double)(CLOCKS_PER_SEC); //realiza o cálculo do tempo gasto pela ordenação

    cout << instance.name << ": " << tempo << endl; //printa a instancia lida e o tempo que demorou para resolver

    return 0;
}