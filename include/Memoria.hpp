#ifndef Memoria_H
#define Memoria_H

#include "Tabuleiro.hpp"
using namespace std;

class Memoria : public Tabuleiro
{
public:
    Memoria();

    virtual int confereGanhador() override;

    bool ehJogadaValida(int x, int y, int x2, int y2, char jogadorDaVez);
    void validaJogada(int x, int y, int x2, int y2, char jogadorDaVez);
    bool formamPares(int x, int y, int x2, int y2, char jogadorDaVez);
    void validaPares(int x, int y, int x2, int y2, char jogadorDaVez);
    bool verificarFimDeJogo();

private:
    void inicializaTabuleiroSimbolos();
    int pontosJogador1;
    int pontosJogador2;
    int jogadorAtual;
    char **aux;
};

#endif