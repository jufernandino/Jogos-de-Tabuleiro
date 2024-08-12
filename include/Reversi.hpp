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

  virtual void validaJogada(int x, int y, char z) override; // sobrecarga
  bool ehJogadaValida(int x, int y, char jogadorDaVez);
  bool existeMovimentoPossivel(char jogadorDaVez); // verifica se existem movimento a serem feitos no turno do jogador
  void mostrarLocaisJogada(char jogador);          // mostrar locais de possíveis jogadas
  bool verificarFimDeJogo();                       // chamada todas as vezes que um movimento é feito

private:
  char jogadorAtual; // variável para armazenar qual a peça do jogador atual (ou X ou O)
  void inverterPecas(int x, int y, char jogadorDaVez);
};

#endif