#ifndef TABULEIRO_H
#define TABULEIRO_H

class Tabuleiro{
    protected:
        int _colunas;
        int _linhas;

    public:
        Tabuleiro(); //Construtor
        void ImprimeTabuleiro();
};

#endif