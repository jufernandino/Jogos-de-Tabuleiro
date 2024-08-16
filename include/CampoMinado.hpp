#ifndef CampoMinado_H
#define CampoMinado_H
#include "Tabuleiro.hpp"

using namespace std;

class CampoMinado : public Tabuleiro
{
public:
  CampoMinado();

  void iniciaTabuleiro();
  int minasAdj(int linha, int coluna);
  void revelaCelula(int linha, int coluna);
  bool validaJogadaCampoMinado(int linha, int coluna);
  bool escolheuBomba(int linha, int coluna);
  int confereGanhador() override;
  int jogarCampoMinado();

private:
  int bombas;
  int posicao_minas[2][10];
};

#endif