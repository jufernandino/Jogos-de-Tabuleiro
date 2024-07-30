#ifndef Reversi_H
#define Reversi_H
#include "Tabuleiro.hpp"

using namespace std;


class Reversi : public Tabuleiro {
  public: 
    Reversi();

    virtual int confereGanhador() override;

    void inicializarJogo(int linha, int coluna); //específica do Reversi, configura o tabuleiro e as posições iniciais das peças

    virtual void validaJogada(int x, int y, char z) override; //sobrecarga

    bool verificarFimDeJogo(); //chamada todas as vezes que um movimento é feito
/*
    
    void fazerMovimento(int linha, int coluna);
    
    //void verificarMovimentoValido(int linha, int coluna); //não precisa, já usamos a getMovimento e a validaJogada

    void mudarJogador();

    void colocarPeca(int linha, int coluna);

    void inverterPecas(int linha, int coluna);
    
    int contarPecas(char cor);
  
*/
  private:
    char jogadorAtual; // variável para armazenar qual a peça do jogador atual (ou X ou O)

};

#endif