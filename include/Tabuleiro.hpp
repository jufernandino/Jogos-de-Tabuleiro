#ifndef Tabuleiro_H
#define Tabuleiro_H
#include <iostream>
#include <string>

using namespace std;

class Tabuleiro{
  public: 
  char** p;
  int rows;
  int columns;

  Tabuleiro();

  void validaJogada(int x, int y, char z);

  void liberaMemoria();

  virtual void criaTabuleiro() = 0;

  virtual void imprimeTabuleiro() = 0;

  virtual int confereGanhador() = 0;

};

#endif