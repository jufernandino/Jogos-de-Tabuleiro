/*
#ifndef CAMPOMINADO_H
#define CAMPOMINADO_H
#include "Tabuleiro.hpp"

using namespace std;

class CampoMinado : public Tabuleiro
{
public:
  CampoMinado();

  void iniciaTabuleiro();
  int minasAdj(int linha, int coluna);
  void revelaCelula(int linha, int coluna);
  bool validaJogada(int linha, int coluna);
  bool escolheuBomba(int linha, int coluna);
  int confereGanhador() override;
  void jogarCampoMinado();

private:
  int bombas;
  int posicao_minas[2][bombas];

};

#endif
*/