#include "hanoi.h"
#include <iostream>

using namespace std;

int main(){
    //system("clear||cls");
    int n;
    cout << "Digite a quantidade de aneis: ";
    cin >> n;

    hanoi h(n);

    h.resolve();

    return 0;
}