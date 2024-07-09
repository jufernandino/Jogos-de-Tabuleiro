#ifndef TicTacToe_H
#define TicTacToe_H
#include "Tabuleiro.hpp"
#include <iostream>
#include <string>

using namespace std;

class TicTacToe : public Tabuleiro{
  public: 

  TicTacToe();

  void validaJogada(int x, int y, char z);

  int confereGanhador();
};

#endif