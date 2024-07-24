#pragma once

class No{
    public:
        No(){
            conteudo = 0;
            proximo = nullptr;
        };

        int conteudo;
        No *proximo;
};