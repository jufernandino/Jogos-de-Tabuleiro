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

  void criaTabuleiro(int x, int y);
  
  void atualizaTabuleiro(int x, int y, char z);

  void liberaMemoria();
};

#endif