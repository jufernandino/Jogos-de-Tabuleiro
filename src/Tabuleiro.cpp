#include "Tabuleiro.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

Tabuleiro::Tabuleiro() {
  this->rows = 0;
  this->columns = 0;
}

void Tabuleiro::validaJogada(int x, int y, char z) {
  if (x < this->rows && y < this->columns && p[x][y] == ' ') {
    p[x][y] = z;
  }
}

void Tabuleiro::liberaMemoria() {
  for (int i = 0; i < rows; i++) {
    delete[] p[i];
  }
  delete[] p;
}
