#ifndef Reversi_H
#define Reversi_H
#include "Tabuleiro.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Reversi : public Tabuleiro
{

public:
    Reversi(); // Construtor

    void inicializarJogo();                               // Metodo para configurar o tabuleiro, as posições iniciais das peças e qual jogador que começa
    void exibirTabuleiro();                               // Metodo para exibir o estado atual do tabuleiro
    bool fazerMovimento(int linha, int coluna);           // Metodo para tentar fazer um movimento (Retorna true se o movimento for válido e realizado,false caso contrário.)
    bool verificarMovimentoValido(int linha, int coluna); // Verifica se o movimento é válido
    void mudarJogador();                                  // Metodo para alternar os jogadores
    bool verificarFimDeJogo();                            // Verifica se o jogo terminou (não há mais movimentos ou o tabuleiro esta cheio)
    void mostrarResultado();                              // Exibe o resultado final do jogo

private:
    static const int TAMANHO_TABULEIRO = 8; // Tamanho do tabuleiro é constante 8x8
    Tabuleiro tabuleiro;
    char jogadorAtual; // variável para armazenar qual a peça do jogador atual (ou X ou O)

    void colocarPeca(int linha, int coluna);   // coloca a peça do jogador atual na posição especificada
    void inverterPecas(int linha, int coluna); // inverte as peças adversarias
    int contarPecas(char cor);                 // Conta quantas peças (X ou O) tem no tabuleiro.
};

#endif