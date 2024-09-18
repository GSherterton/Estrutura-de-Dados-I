#pragma once
#include <vector>
#include <string>

using namespace std;

class hanoi{
    public:
        vector<int> A;
        vector<int> B;
        vector<int> C;

        
        hanoi();
        hanoi(int n);

        void resolve();

    private:
        int maior;

        void imprime(bool tem, const vector<int>& vec, int i);
        string espaco(int n);
        void exibe();

        void move(vector<int>& origin,vector<int>& dest);

        void resolve(int n, vector<int>& origin, vector<int>& interm, vector<int>& dest);
};