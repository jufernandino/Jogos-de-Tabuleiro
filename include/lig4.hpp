#ifndef lig4_H
#define lig4_H
#include "Tabuleiro.hpp"
#include <iostream>
#include <string>

using namespace std;

class lig4 : public Tabuleiro{
  public: 

  lig4();

  virtual void validaJogada(int x, int y, char z) override;

  virtual int confereGanhador() override;

};

#endif