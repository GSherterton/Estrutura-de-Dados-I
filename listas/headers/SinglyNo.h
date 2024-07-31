#pragma once

class SinglyNo{
    public:
        SinglyNo(){
            conteudo = 0;
            proximo = nullptr;
        };

        int conteudo;
        SinglyNo *proximo;
};