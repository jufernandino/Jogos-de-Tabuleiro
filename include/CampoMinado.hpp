#ifndef CAMPOMINADO_H
#define CAMPOMINADO_H
#include "Tabuleiro.hpp"

using namespace std;

class CampoMinado : public Tabuleiro
{
public:
  CampoMinado();

  void jogarCampoMinado();

  bool validaJogada(int x, int y);
  int confereGanhador() override;
  bool verificaFimDeJogo();

private:
  int bombas;

};

#endif