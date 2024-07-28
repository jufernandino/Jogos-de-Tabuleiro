#ifndef Reversi_H
#define Reversi_H
#include "Tabuleiro.hpp"

using namespace std;

/*

class Reversi : public Tabuleiro {
  public: 
    Reversi(); //construtor

    void inicializarJogo(); //específica do Reversi, configura o tabuleiro e as posições iniciais das peças

    virtual void imprimeTabuleiro() override;

    void fazerMovimento(int linha, int coluna);
    
    void verificarMovimentoValido(int linha, int coluna);
    
    void mudarJogador();

    bool verificarFimDeJogo(); //chamada todas as vezes que um movimento é feito

    virtual int confereGanhador() override;

  private:
    Tabuleiro tabuleiro;
        
    char jogadorAtual; // variável para armazenar qual a peça do jogador atual (ou X ou O)

    void colocarPeca(int linha, int coluna);
    
    void inverterPecas(int linha, int coluna);
    
    int contarPecas(char cor);
};

*/

#endif