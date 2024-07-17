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

  void criaTabuleiro();

  void liberaMemoria();

  virtual void validaJogada(int x, int y, char z);

  virtual void imprimeTabuleiro() = 0;

  virtual int confereGanhador() = 0;

};

#endif