#ifndef Reversi_H
#define Reversi_H
#include "Tabuleiro.hpp"

using namespace std;

class Reversi : public Tabuleiro
{
public:
  Reversi();

  virtual int confereGanhador() override;

  void inicializarJogo();

  virtual void validaJogada(int x, int y, char jogadorDaVez) override; // sobrecarga
  bool ehJogadaValida(int x, int y, char jogadorDaVez);
  void mostrarLocaisJogada(char jogador); // Método para mostrar locais de jogada possíveis
  bool verificarFimDeJogo();              // chamada todas as vezes que um movimento é feito
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
  void inverterPecas(int x, int y, char jogadorDaVez);
};

#endif