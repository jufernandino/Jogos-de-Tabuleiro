#ifndef TicTacToe_H
#define TicTacToe_H
#include "Tabuleiro.hpp"
#include <iostream>
#include <string>

using namespace std;

class TicTacToe : public Tabuleiro{
  public: 

  TicTacToe();

  virtual int confereGanhador() override;
};

#endif