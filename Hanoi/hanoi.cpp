#include "hanoi.h"
#include <iostream>

#ifdef _WIN32
#define WINDOWS_SYSTEM
    #include <Windows.h>
#else
    #include <unistd.h>
#endif


hanoi::hanoi(){}

hanoi::hanoi(int n){
    for(int i = n; i > 0; i--){//Preenche a pilha A
        A.push_back(i);
    }

    maior = 10;
}

void hanoi::imprime(bool tem, const vector<int>& vec, int i){
    i--;
    cout << espaco((tem ? (10 - vec[i]) : 11));
    
    if(tem){
        cout << "┎";
        for(int j = 0; j < vec[i]; j++){
            cout << "─";
        }
    }

    cout << "┃";

    if(tem){
        for(int j = 0; j < vec[i]; j++){
            cout << "─";
        }
        cout << "┒";
    }

    cout << espaco((tem ? (10 - vec[i]) : 11));
}

string hanoi::espaco(int n){
    string str;

    for(int i = 0; i < n; i++){
        str.push_back(' ');
    }

    return str;
}

void hanoi::exibe(){
    system("clear||cls");

    int vazio = 15;

    vector<int> size(3, 0);
    size[0] = A.size();
    size[1] = B.size();
    size[2] = C.size();

    vazio -= maior;

    for(int i = 0; i < vazio; i++){
        cout << "\n";
    }

    vector<bool> tem(3, false);
    for(int i = maior; i > 0; i--){
        for(int j = 0; j < 3; j++){//verifica se ja comecou a imprimir cada torre
            if(i <= size[j]){
                tem[j] = true;
            }
        }

        cout << espaco(5);
        imprime(tem[0], A, i);
        cout << espaco(10);
        imprime(tem[1], B, i);
        cout << espaco(10);
        imprime(tem[2], C, i);
        cout << "\n";
    }

    /*
    "     ┎┏┍┌     ┐┑┓┒\n"
    "     ┖┗┕└     ┘┙┛┚   ";
            "               ┎┒\n"
    */

    //tem 20 de tamanho e 5 espacos
    cout << "     ┏━━━━━━━━━━┻━━━━━━━━━━┓          ┏━━━━━━━━━━┻━━━━━━━━━━┓          ┏━━━━━━━━━━┻━━━━━━━━━━┓         \n"
            "     ┗━━━━━━━━━━━━━━━━━━━━━┛          ┗━━━━━━━━━━━━━━━━━━━━━┛          ┗━━━━━━━━━━━━━━━━━━━━━┛         \n";

    //sleep de 2 segundos para conseguir visualizar os movimentos do hanoi
    #ifdef WINDOWS_SYSTEM
        Sleep( 2000 );
    #else
        sleep(2);
    #endif
}

void hanoi::move(vector<int>& origin,vector<int>& dest){
    if(origin.empty()){
        cout << "Não há peças para mover!\n";
        return;
    }

    if(origin.back() > (dest.empty() ? origin.back() : dest.back())){
        cout << "Tentou fazer um movimento irregular!\n";
        return;
    }

    dest.push_back(origin.back());
    origin.pop_back();
}

void hanoi::resolve(int n, vector<int>& origin, vector<int>& interm, vector<int>& dest){
    if(n == 1){
        move(origin, dest);
        exibe();
        return;
    }

    resolve(n-1, origin, dest, interm);
    move(origin, dest);
    exibe();
    resolve(n-1, interm, origin, dest);

    return;
}

void hanoi::resolve(){
    exibe();
    resolve(A.size(), A, B, C);
}